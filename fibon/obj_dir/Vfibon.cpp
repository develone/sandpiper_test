// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibon.h for the primary calling header

#include "Vfibon.h"            // For This
#include "Vfibon__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vfibon) {
    Vfibon__Syms* __restrict vlSymsp = __VlSymsp = new Vfibon__Syms(this, name());
    Vfibon* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfibon::__Vconfigure(Vfibon__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vfibon::~Vfibon() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vfibon::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfibon::eval\n"); );
    Vfibon__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfibon* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vfibon::_eval_initial_loop(Vfibon__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vfibon::_eval(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_eval\n"); );
    Vfibon* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vfibon::_eval_initial(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_eval_initial\n"); );
    Vfibon* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfibon::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::final\n"); );
    // Variables
    Vfibon__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfibon* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfibon::_eval_settle(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_eval_settle\n"); );
    Vfibon* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData Vfibon::_change_request(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_change_request\n"); );
    Vfibon* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfibon::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
}
#endif // VL_DEBUG

void Vfibon::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    cyc_cnt = VL_RAND_RESET_I(32);
    passed = VL_RAND_RESET_I(1);
    failed = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}
