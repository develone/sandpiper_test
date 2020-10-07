// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated.h"

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(passed,0,0);
    VL_OUT8(failed,0,0);
    VL_IN(cyc_cnt,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__clkP_EXE_instr_valid_a5,0,0);
    VL_SIG8(top__DOT__clkP_EXE_instr_valid_a6,0,0);
    VL_SIG8(top__DOT__EXE_aluop_a5,3,0);
    VL_SIG8(top__DOT__EXE_br_a5,0,0);
    VL_SIG8(top__DOT__EXE_br_a6,0,0);
    VL_SIG8(top__DOT__EXE_cc_a6,2,0);
    VL_SIG8(top__DOT__EXE_dest_a5,2,0);
    VL_SIG8(top__DOT__EXE_dest_a6,2,0);
    VL_SIG8(top__DOT__EXE_instr_valid_a4,0,0);
    VL_SIG8(top__DOT__EXE_instr_valid_a5,0,0);
    VL_SIG8(top__DOT__EXE_instr_valid_a6,0,0);
    VL_SIG8(top__DOT__EXE_mem_op_a7,0,0);
    VL_SIG8(top__DOT__EXE_mem_op_a8,0,0);
    VL_SIG8(top__DOT__EXE_offset6_a5,5,0);
    VL_SIG8(top__DOT__EXE_valid_br_taken_a6,0,0);
    VL_SIG8(top__DOT__EXE_valid_ld_a4,0,0);
    VL_SIG8(top__DOT__EXE_valid_ld_a5,0,0);
    VL_SIG8(top__DOT__EXE_valid_ld_a6,0,0);
    VL_SIG8(top__DOT__EXE_valid_mem_instr_a4,0,0);
    VL_SIG8(top__DOT__EXE_valid_mem_instr_a5,0,0);
    VL_SIG8(top__DOT__EXE_valid_mem_instr_a6,0,0);
    VL_SIG8(top__DOT__EXE_valid_st_a4,0,0);
    VL_SIG8(top__DOT__EXE_valid_st_a5,0,0);
    VL_SIG8(top__DOT__EXE_valid_st_a6,0,0);
    VL_SIG8(top__DOT__EXE_valid_st_a7,0,0);
    VL_SIG8(top__DOT__FETCH_instr_valid_a1,0,0);
    VL_SIG8(top__DOT__FETCH_instr_valid_a2,0,0);
    VL_SIG8(top__DOT__FETCH_reset_a2,0,0);
    VL_SIG8(top__DOT__RESP_FetchPending_a1,0,0);
    VL_SIG8(top__DOT__RESP_FetchPending_a2,0,0);
    VL_SIG8(top__DOT__RESP_FetchPending_a3,0,0);
    VL_SIG8(top__DOT__RESP_LoadPending_a1,0,0);
    VL_SIG8(top__DOT__RESP_LoadPending_a2,0,0);
    VL_SIG8(top__DOT__RESP_LoadPending_a3,0,0);
    VL_SIG8(top__DOT__RESP_StorePending_a2,0,0);
    VL_SIG8(top__DOT__RESP_StorePending_a3,0,0);
    VL_SIG8(top__DOT__RESP_fetch_resp_valid_a3,0,0);
    VL_SIG8(top__DOT__RESP_ld_resp_valid_a3,0,0);
    VL_SIG8(top__DOT__RESP_ld_resp_valid_a4,0,0);
    VL_SIG8(top__DOT__RESP_mem_resp_a3,0,0);
    VL_SIG8(top__DOT__RESP_next_store_pending_a2,0,0);
    VL_SIG8(top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1,0,0);
    VL_SIG8(top__DOT__gen_clkP_EXE_instr_valid_a5__DOT__latched_clk_en,0,0);
    VL_SIG8(top__DOT__gen_clkP_EXE_instr_valid_a6__DOT__latched_clk_en,0,0);
    VL_SIG16(top__DOT__L0_Cnt_n1,15,0);
    VL_SIG16(top__DOT__L0_Cnt_a0,15,0);
    VL_SIG16(top__DOT__EXE_ir_a3,15,0);
    VL_SIG16(top__DOT__EXE_ir_a4,15,0);
    VL_SIG16(top__DOT__EXE_reg_a_a5,15,0);
    VL_SIG16(top__DOT__EXE_reg_b_a5,15,0);
    VL_SIG16(top__DOT__RESP_mem_rdata_a3,15,0);
    VL_SIGW(top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1,256,0,9);
    VL_SIGW(top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2,256,0,9);
    VL_SIG16(top__DOT__rf__DOT__data[8],15,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a6,0,0);
    VL_SIG8(__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a5,0,0);
    VL_SIG16(top__DOT____Vcellout__alu__f,15,0);
    VL_SIG16(top__DOT____Vcellinp__alu__b,15,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _initial__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__9(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
