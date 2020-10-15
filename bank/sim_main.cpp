// DESCRIPTION: Verilator Example: Top level main for invoking model
//
// Copyright 2003-2016 by Wilson Snyder. This program is free software; you can
// redistribute it and/or modify it under the terms of either the GNU
// Lesser General Public License Version 3 or the Perl Artistic License
// Version 2.0.

#include <verilated.h>        // Defines common routines
#include "Vmakerchip.h"        // From Verilating "makerchip.v"
#if VM_TRACE
# include <verilated_vcd_c.h>    // Trace file format header
#endif

Vmakerchip *makerchip;            // Instantiation of module

vluint64_t main_time = 0;    // Current simulation time (64-bit unsigned)

double sc_time_stamp () {    // Called by $time in Verilog
    return main_time;        // Note does conversion to real, to match SystemC
}

int main(int argc, char **argv, char **env) {
    if (0 && argc && argv && env) {}    // Prevent unused variable warnings
    makerchip = new Vmakerchip;        // Create instance of module

    Verilated::commandArgs(argc, argv);
    Verilated::debug(0);

#if VM_TRACE            // If verilator was invoked with --trace
    Verilated::traceEverOn(true);    // Verilator must compute traced signals
    VL_PRINTF("Enabling waves...\n");
    VerilatedVcdC* tfp = new VerilatedVcdC;
    makerchip->trace (tfp, 99);    // Trace 99 levels of hierarchy
    tfp->open ("vlt_dump.vcd");    // Open the dump file
#endif

    int RESET_DURATION = 4;  // in cycles

    // Set some inputs
    makerchip->clk = 0;
    makerchip->reset_async = 1;
    makerchip->passed = 0;
    makerchip->failed = 0;

    // Main loop.
    // Terminate on pass/fail before falling clock or on primary (lower) cycle limit.
    // The primary cycle limit is checked before rising clock only, while explicit termination
    // is detected before falling edge. As a backdoor, simulation is allowed to continue
    // if terminal condition is indicated during max-cycle check.
    // So, to extend timeout assign passed and failed to !clk || done.
    while (main_time < 400000 &&
           (makerchip->clk ? !makerchip->passed && !makerchip->failed
                           : main_time < 1200 || (makerchip->passed && makerchip->failed)
           ) && !Verilated::gotFinish()) {
        
        makerchip->clk = !makerchip->clk;

	// I had trouble driving inputs from C++ to behave as if driven by a flop.  So, I drive
	// *_async inputs on falling edge and capture them in makerchip.sv on rising-edge flop.
	if (!makerchip->clk) {
          if (main_time >= RESET_DURATION * 2) {  // Reset duration
            makerchip->reset_async = 0;    // Deassert reset
	  }
        }

        makerchip->eval();        // Evaluate model
#if VM_TRACE
        if (tfp) tfp->dump (main_time);    // Create waveform trace for this timestamp
#endif

        // Read outputs
        //VL_PRINTF ("[%" VL_PRI64 "d] %x %x %x\n",
        //       main_time, makerchip->clk, makerchip->reset, makerchip->passed);

        main_time++;        // Time passes...
    }

    makerchip->final();

#if VM_TRACE
    if (tfp) tfp->close();
#endif

    if (makerchip->failed) {
        VL_PRINTF ("Simulation FAILED!!!\n");
    } else if (makerchip->passed) {
        VL_PRINTF ("Simulation PASSED!!!\n");
    } else {
        VL_PRINTF ("Simulation reached max cycles.\n");
        //abort();
    }

    exit(0L);
}
