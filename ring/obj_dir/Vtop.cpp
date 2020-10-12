// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.tlv", 35, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("top.tlv", 35, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->failed = (0x50U < vlTOPp->cyc_cnt);
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2[0U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2[1U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2[2U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2[3U] 
        = vlTOPp->clk;
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__clkP_RingStop_BP1_avail_a1
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4
        [3U];
    vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1
        [0U];
    vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1
        [1U];
    vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1
        [2U];
    vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__clkP_RingStop_RG_valid_a2
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__clkP_RingStop_BP2_avail_a1
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__clkP_RingStop_STALL0_avail_a2
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__clkP_RingStop_STALL1_avail_a2
        [3U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2
        [0U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2
        [1U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2
        [2U];
    vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__clkP_RingStop_STALL2_avail_a2
        [3U];
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v0;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v0;
    CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v0;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v0;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v0;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v0;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v0;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v1;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v1;
    CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v1;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v1;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v1;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v1;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v1;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v2;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v2;
    CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v2;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v2;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v2;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v2;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v2;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v3;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v3;
    CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v3;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v3;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v3;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v3;
    CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v3;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
    CData/*1:0*/ __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0;
    CData/*1:0*/ __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
    WData/*99:0*/ __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[4];
    WData/*99:0*/ __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[4];
    WData/*99:0*/ __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[4];
    WData/*99:0*/ __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[4];
    WData/*99:0*/ __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[4];
    WData/*99:0*/ __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[4];
    WData/*99:0*/ __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[4];
    WData/*99:0*/ __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[4];
    // Body
    __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
    __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
    __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
    __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
    __Vdlyvset__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0 = 0U;
    __Vdlyvset__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0 = 0U;
    __Vdlyvset__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0 = 0U;
    __Vdlyvset__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0 = 0U;
    __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
    __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
    __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
    __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
    __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
    __Vdlyvset__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0 = 0U;
    __Vdlyvset__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0 = 0U;
    __Vdlyvset__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0 = 0U;
    __Vdlyvset__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0 = 0U;
    VL_WRITEF("Cycle: %0#\n",16,vlTOPp->top__DOT__Tb_COUNT_CycCount_a1);
    if (VL_UNLIKELY((((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
                      & (~ (IData)(vlTOPp->reset))) 
                     & (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a1)))) {
        VL_WRITEF("|send[0]\n");
        VL_WRITEF("Sender: %0#, Orig. Cyc: %0#, Dest: %0#, Resp: %0#\n",
                  2,(3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                           << 2U) | 
                                          (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                            : (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                << 5U) | (0x18U & (
                                                   vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                   << 3U))))),
                  16,(0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                   : (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                       << 5U) | (0x18U 
                                                 & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                    << 3U)))) 
                                 >> 5U)),2,(3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                                    ? 
                                                   (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                     << 4U) 
                                                    | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                        << 2U) 
                                                       | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                           << 1U) 
                                                          | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                                    : 
                                                   (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                     << 5U) 
                                                    | (0x18U 
                                                       & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                          << 3U)))) 
                                                  >> 3U)),
                  1,(1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                             ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                 << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                            << 2U) 
                                           | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                               << 1U) 
                                              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                             : (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                 << 5U) | (0x18U & 
                                           (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                            << 3U)))) 
                           >> 2U)));
    }
    if (VL_UNLIKELY((((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
                      & (~ (IData)(vlTOPp->reset))) 
                     & (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a1)))) {
        VL_WRITEF("|send[1]\n");
        VL_WRITEF("Sender: %0#, Orig. Cyc: %0#, Dest: %0#, Resp: %0#\n",
                  2,(3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                           << 2U) | 
                                          (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                            : (1U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                      << 5U) | (0x18U 
                                                & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                   << 2U)))))),
                  16,(0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                   : (1U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                             << 5U) 
                                            | (0x18U 
                                               & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                  << 2U))))) 
                                 >> 5U)),2,(3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                                    ? 
                                                   (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                     << 4U) 
                                                    | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                        << 2U) 
                                                       | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                           << 1U) 
                                                          | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                                    : 
                                                   (1U 
                                                    | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                        << 5U) 
                                                       | (0x18U 
                                                          & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                             << 2U))))) 
                                                  >> 3U)),
                  1,(1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                             ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                 << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                            << 2U) 
                                           | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                               << 1U) 
                                              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                             : (1U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                       << 5U) | (0x18U 
                                                 & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                    << 2U))))) 
                           >> 2U)));
    }
    if (VL_UNLIKELY((((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
                      & (~ (IData)(vlTOPp->reset))) 
                     & (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a1)))) {
        VL_WRITEF("|send[2]\n");
        VL_WRITEF("Sender: %0#, Orig. Cyc: %0#, Dest: %0#, Resp: %0#\n",
                  2,(3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                           << 2U) | 
                                          (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                            : (2U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                      << 5U) | (0x18U 
                                                & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                   << 1U)))))),
                  16,(0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                   : (2U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                             << 5U) 
                                            | (0x18U 
                                               & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                  << 1U))))) 
                                 >> 5U)),2,(3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                                    ? 
                                                   (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                     << 4U) 
                                                    | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                        << 2U) 
                                                       | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                           << 1U) 
                                                          | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                                    : 
                                                   (2U 
                                                    | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                        << 5U) 
                                                       | (0x18U 
                                                          & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                             << 1U))))) 
                                                  >> 3U)),
                  1,(1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                             ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                 << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                            << 2U) 
                                           | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                               << 1U) 
                                              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                             : (2U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                       << 5U) | (0x18U 
                                                 & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                    << 1U))))) 
                           >> 2U)));
    }
    if (VL_UNLIKELY((((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
                      & (~ (IData)(vlTOPp->reset))) 
                     & (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a1)))) {
        VL_WRITEF("|send[3]\n");
        VL_WRITEF("Sender: %0#, Orig. Cyc: %0#, Dest: %0#, Resp: %0#\n",
                  2,(3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                           << 2U) | 
                                          (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                            : (3U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                      << 5U) | (0x18U 
                                                & vlTOPp->top__DOT__RW_rand_vect[0U]))))),
                  16,(0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                   : (3U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                             << 5U) 
                                            | (0x18U 
                                               & vlTOPp->top__DOT__RW_rand_vect[0U])))) 
                                 >> 5U)),2,(3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                                    ? 
                                                   (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                     << 4U) 
                                                    | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                        << 2U) 
                                                       | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                           << 1U) 
                                                          | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                                    : 
                                                   (3U 
                                                    | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                        << 5U) 
                                                       | (0x18U 
                                                          & vlTOPp->top__DOT__RW_rand_vect[0U])))) 
                                                  >> 3U)),
                  1,(1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                             ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                 << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                            << 2U) 
                                           | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                               << 1U) 
                                              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                             : (3U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                       << 5U) | (0x18U 
                                                 & vlTOPp->top__DOT__RW_rand_vect[0U])))) 
                           >> 2U)));
    }
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1 
        = vlTOPp->reset;
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_trans_valid_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_trans_valid_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_trans_valid_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_trans_valid_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_trans_valid_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_trans_valid_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_trans_valid_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_trans_valid_a2;
    vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a2 
        = vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a1;
    vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a2 
        = vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a1;
    vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a2 
        = vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a1;
    vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a2 
        = vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a1;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2 = 0U;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2 = 0U;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2 = 0U;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2 = 0U;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a0;
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U];
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U] 
        = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U];
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a4) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt = 0U;
    }
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a4) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt = 0U;
    }
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a4) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt = 0U;
    }
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a4) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt = 0U;
    }
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_FIFO2_OUT_avail_a1));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_FIFO2_OUT_avail_a1));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_FIFO2_OUT_avail_a1));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_FIFO2_OUT_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a0;
    __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v0 
        = vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1
        [0U];
    __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v1 
        = vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1
        [1U];
    __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v2 
        = vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1
        [2U];
    __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v3 
        = vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1
        [3U];
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a3;
    __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v0 
        = vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0
        [0U];
    __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v1 
        = vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0
        [1U];
    __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v2 
        = vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0
        [2U];
    __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v3 
        = vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0
        [3U];
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a1;
    vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_reset_a2 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_reset_a2 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_reset_a2 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_reset_a2 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_reset_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_reset_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_reset_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_reset_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1;
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr) {
            __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[0U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[0U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[1U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[1U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[2U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[2U];
            __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[3U] 
                = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[3U];
            __Vdlyvset__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0 = 1U;
            __Vdlyvdim0__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
            __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail)));
        }
    }
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt = 0U;
    }
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt = 0U;
    }
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt = 0U;
    }
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt = 0U;
    }
    __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v0 
        = vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0
        [0U];
    __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v1 
        = vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0
        [1U];
    __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v2 
        = vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0
        [2U];
    __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v3 
        = vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0
        [3U];
    if (vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    if (vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    if (vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    if (vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head) {
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[3U];
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr) {
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[3U];
        }
    }
    __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v0 = 
        vlTOPp->top__DOT__RingStop_RG_dest_a1[0U];
    __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v1 = 
        vlTOPp->top__DOT__RingStop_RG_dest_a1[1U];
    __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v2 = 
        vlTOPp->top__DOT__RingStop_RG_dest_a1[2U];
    __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v3 = 
        vlTOPp->top__DOT__RingStop_RG_dest_a1[3U];
    __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v0 
        = vlTOPp->top__DOT__RingStop_RG_pass_on_a1[0U];
    __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v1 
        = vlTOPp->top__DOT__RingStop_RG_pass_on_a1[1U];
    __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v2 
        = vlTOPp->top__DOT__RingStop_RG_pass_on_a1[2U];
    __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v3 
        = vlTOPp->top__DOT__RingStop_RG_pass_on_a1[3U];
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2 = 0U;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2 = 0U;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2 = 0U;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2 = 0U;
    __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v0 
        = vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1
        [0U];
    __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v1 
        = vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1
        [1U];
    __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v2 
        = vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1
        [2U];
    __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v3 
        = vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1
        [3U];
    __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v0 
        = vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
        [0U];
    __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v1 
        = vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
        [1U];
    __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v2 
        = vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
        [2U];
    __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v3 
        = vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
        [3U];
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2[0U] 
        = __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v0;
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2[1U] 
        = __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v1;
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2[2U] 
        = __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v2;
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2[3U] 
        = __Vdlyvval__top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2__v3;
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1[0U] 
        = __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v0;
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1[1U] 
        = __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v1;
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1[2U] 
        = __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v2;
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1[3U] 
        = __Vdlyvval__top__DOT__RingStop_BP1_Trans_cyc_cnt_a1__v3;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail 
        = __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1[0U] 
        = __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v0;
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1[1U] 
        = __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v1;
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1[2U] 
        = __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v2;
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1[3U] 
        = __Vdlyvval__top__DOT__RingStop_BP2_Trans_cyc_cnt_a1__v3;
    vlTOPp->top__DOT__RingStop_RG_dest_a2[0U] = __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v0;
    vlTOPp->top__DOT__RingStop_RG_dest_a2[1U] = __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v1;
    vlTOPp->top__DOT__RingStop_RG_dest_a2[2U] = __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v2;
    vlTOPp->top__DOT__RingStop_RG_dest_a2[3U] = __Vdlyvval__top__DOT__RingStop_RG_dest_a2__v3;
    vlTOPp->top__DOT__RingStop_RG_pass_on_a2[0U] = __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v0;
    vlTOPp->top__DOT__RingStop_RG_pass_on_a2[1U] = __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v1;
    vlTOPp->top__DOT__RingStop_RG_pass_on_a2[2U] = __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v2;
    vlTOPp->top__DOT__RingStop_RG_pass_on_a2[3U] = __Vdlyvval__top__DOT__RingStop_RG_pass_on_a2__v3;
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2[0U] 
        = __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v0;
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2[1U] 
        = __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v1;
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2[2U] 
        = __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v2;
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2[3U] 
        = __Vdlyvval__top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2__v3;
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2[0U] 
        = __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v0;
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2[1U] 
        = __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v1;
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2[2U] 
        = __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v2;
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2[3U] 
        = __Vdlyvval__top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2__v3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_trans_valid_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_trans_valid_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_trans_valid_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_trans_valid_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a1;
    if (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) {
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U] = 0x4e4684aU;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U] = 0xc45f864U;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U] = 0x76874654U;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U] = 0xf3048b46U;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U] = 0x5cd84848U;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U] = 0x6684e132U;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U] = 0x713d5431U;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U] = 0x7163e168U;
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U] = 0U;
    } else {
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U] 
            = ((0xfffffffeU & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                               << 1U)) ^ (0xc5U & (- (IData)(
                                                             (1U 
                                                              & vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U])))));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U] 
            = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                                   << 1U)));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U] 
            = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                                   << 1U)));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U] 
            = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                                   << 1U)));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U] 
            = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                                   << 1U)));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U] 
            = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                                   << 1U)));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U] 
            = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                                   << 1U)));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U] 
            = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                                   << 1U)));
        vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U] 
            = (1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                     >> 0x1fU));
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a4) {
        __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1) {
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a2;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_reset_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_reset_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_reset_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_reset_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1) {
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1) {
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1) {
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr;
    if (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1) {
        __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head = 0U;
    } else {
        if (vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1) {
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[0U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][0U];
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[1U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][1U];
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[2U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][2U];
            vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[3U] 
                = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr
                [vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head][3U];
            __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head)));
        }
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head 
        = __Vdly__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
    if (__Vdlyvset__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0) {
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][0U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[0U];
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][1U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[1U];
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][2U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[2U];
        vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vdlyvdim0__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0][3U] 
            = __Vdlyvval__top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr__v0[3U];
    }
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a2 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a1;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a2;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1));
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a2 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a2 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a2 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a2 
        = vlTOPp->top__DOT__L0_reset_a1;
    vlTOPp->top__DOT__L0_reset_a1 = vlTOPp->reset;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__12(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__12\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__13(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__13\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__14(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__14\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__15(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__15\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__16(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__16\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a3;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__17(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__17\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a3;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__18(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__18\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a3;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__19(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__19\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a4 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a3;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__20(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__20\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_a1 = 1U;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_request_a1 
        = (0U == (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__21(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__21\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_a1 = 1U;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_request_a1 
        = (1U == (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__22(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__22\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_a1 = 1U;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_request_a1 
        = (2U == (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__23(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__23\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_a1 = 1U;
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_request_a1 
        = (3U == (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__28(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__28\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v2 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v3 = 0U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__29(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__29\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__30(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__30\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__31(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__31\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__32(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__32\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a0;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__33(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__33\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_dest_a2 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                       << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                          << 3U)))) 
                 >> 3U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_sender_a2 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                  ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                      << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                 << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                  : (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                      << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                         << 3U)))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__34(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__34\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_dest_a2 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (1U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                             << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                << 2U))))) 
                 >> 3U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_sender_a2 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                  ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                      << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                 << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                  : (1U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                            << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                               << 2U))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__35(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__35\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_dest_a2 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (2U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                             << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                << 1U))))) 
                 >> 3U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_sender_a2 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                  ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                      << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                 << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                  : (2U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                            << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                               << 1U))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__36(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__36\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_dest_a2 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (3U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                             << 5U) | (0x18U & vlTOPp->top__DOT__RW_rand_vect[0U])))) 
                 >> 3U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_sender_a2 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                  ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                      << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                 << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                            << 1U) 
                                           | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                  : (3U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                            << 5U) | (0x18U & vlTOPp->top__DOT__RW_rand_vect[0U])))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__37(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__37\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__38(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__38\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__39(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__39\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__40(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__40\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__41(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__41\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__42(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__42\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__43(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__43\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__44(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__44\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a1;
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a2 
        = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__45(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__45\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a2;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__46(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__46\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a2;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__47(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__47\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a2;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__48(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__48\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a3 
        = vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a2;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__49(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__49\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [0U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0 = 1U;
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v0 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [0U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v0 = 1U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__50(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__50\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [1U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1 = 1U;
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v1 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [1U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v1 = 1U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__51(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__51\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [2U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2 = 1U;
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [2U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v2 = 1U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__52(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__52\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [3U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3 = 1U;
    vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v3 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [3U];
    vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v3 = 1U;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__53(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__53\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp46[4];
    // Body
    VL_EXTEND_WI(100,3, __Vtemp46, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [0U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[0U] 
        = __Vtemp46[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[1U] 
        = __Vtemp46[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[2U] 
        = __Vtemp46[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[3U] 
        = __Vtemp46[3U];
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__54(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__54\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
           & (0U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
           & ((0U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[0U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [3U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [3U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [3U] | (0U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4));
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [3U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1));
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP0_avail_a1)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__55(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__55\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp47[4];
    // Body
    VL_EXTEND_WI(100,3, __Vtemp47, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [1U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[0U] 
        = __Vtemp47[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[1U] 
        = __Vtemp47[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[2U] 
        = __Vtemp47[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[3U] 
        = __Vtemp47[3U];
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__56(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__56\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
           & (1U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
           & ((1U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[1U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [0U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [0U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [0U] | (1U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [0U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP0_avail_a1)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__57(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__57\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp48[4];
    // Body
    VL_EXTEND_WI(100,3, __Vtemp48, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [2U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[0U] 
        = __Vtemp48[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[1U] 
        = __Vtemp48[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[2U] 
        = __Vtemp48[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[3U] 
        = __Vtemp48[3U];
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__58(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__58\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
           & (2U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
           & ((2U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[2U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [1U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [1U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [1U] | (2U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [1U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP0_avail_a1)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__59(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__59\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp49[4];
    // Body
    VL_EXTEND_WI(100,3, __Vtemp49, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [3U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[0U] 
        = __Vtemp49[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[1U] 
        = __Vtemp49[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[2U] 
        = __Vtemp49[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[3U] 
        = __Vtemp49[3U];
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__60(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__60\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
           & (3U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
           & ((3U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[3U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [2U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [2U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [2U] | (3U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [2U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP0_avail_a1)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__61(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__61\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 
        = (1U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U] 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1 
        = (1U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]);
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1 
        = ((2U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                  << 1U)) | (0U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U])));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__62(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__62\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_request_a1));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__63(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__63\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 
        = (1U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U] 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1 
        = (1U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]);
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1 
        = ((2U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                  << 1U)) | (1U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U])));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__64(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__64\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_request_a1));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__65(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__65\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 
        = (1U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U] 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1 
        = (1U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]);
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1 
        = ((2U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                  << 1U)) | (2U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U])));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__66(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__66\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_request_a1));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__67(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__67\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 
        = (1U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U] 
                 >> 1U));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1 
        = (1U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]);
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1 
        = ((2U & ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1) 
                  << 1U)) | (3U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U])));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__68(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__68\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_request_a1));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__69(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__69\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RW_rand_vect[0U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U];
    vlTOPp->top__DOT__RW_rand_vect[1U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U];
    vlTOPp->top__DOT__RW_rand_vect[2U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U];
    vlTOPp->top__DOT__RW_rand_vect[3U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U];
    vlTOPp->top__DOT__RW_rand_vect[4U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U];
    vlTOPp->top__DOT__RW_rand_vect[5U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U];
    vlTOPp->top__DOT__RW_rand_vect[6U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U];
    vlTOPp->top__DOT__RW_rand_vect[7U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U];
    vlTOPp->top__DOT__RW_rand_vect[8U] = ((0xfffffffeU 
                                           & ((IData)(
                                                      (0x7fffffffffffffffULL 
                                                       & (((QData)((IData)(
                                                                           vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                              << 1U)) 
                                          | vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U]);
    vlTOPp->top__DOT__RW_rand_vect[9U] = ((1U & ((IData)(
                                                         (0x7fffffffffffffffULL 
                                                          & (((QData)((IData)(
                                                                              vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                                 >> 0x1fU)) 
                                          | (0xfffffffeU 
                                             & ((IData)(
                                                        ((0x7fffffffffffffffULL 
                                                          & (((QData)((IData)(
                                                                              vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                              << 0x20U) 
                                                             | (QData)((IData)(
                                                                               vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U])))) 
                                                         >> 0x20U)) 
                                                << 1U)));
    vlTOPp->top__DOT__Tb_COUNT_CycCount_a1 = vlTOPp->top__DOT__Tb_COUNT_CycCount_a0;
    vlTOPp->top__DOT__Tb_COUNT_CycCount_a0 = ((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_reset_a2)
                                               ? 0U
                                               : (0xffffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1))));
    vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1 
        = ((0xeU & (IData)(vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1)) 
           | (((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
               & (0U == (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1))) 
              & (0xcU < (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1))));
    vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1 
        = ((0xdU & (IData)(vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1)) 
           | ((((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
                & (0U == (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1))) 
               & (0xcU < (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1))) 
              << 1U));
    vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1 
        = ((0xbU & (IData)(vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1)) 
           | ((((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
                & (0U == (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1))) 
               & (0xcU < (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1))) 
              << 2U));
    vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1 
        = ((7U & (IData)(vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1)) 
           | ((((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
                & (0U == (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1))) 
               & (0xcU < (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1))) 
              << 3U));
    vlTOPp->passed = (0xfU == (IData)(vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__70(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__70\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                      [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__71(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__71\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                      [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__72(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__72\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                      [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__73(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__73\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                      [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__74(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__74\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                      [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__75(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__75\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                      [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__76(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__76\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                      [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__77(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__77\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a1 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a1 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2)
                  ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                      [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a2)))
                  : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                      [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))));
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__78(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__78\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [0U];
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [0U];
}

VL_INLINE_OPT void Vtop::_sequent__TOP__79(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__79\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [1U];
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [1U];
}

VL_INLINE_OPT void Vtop::_sequent__TOP__80(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__80\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [2U];
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [2U];
}

VL_INLINE_OPT void Vtop::_sequent__TOP__81(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__81\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1
        [3U];
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a2 
        = vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1
        [3U];
}

VL_INLINE_OPT void Vtop::_sequent__TOP__82(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__82\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0) {
        vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2[0U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1) {
        vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2[1U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2) {
        vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2[2U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3) {
        vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2[3U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v0) {
        vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2[0U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v1) {
        vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2[1U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v1;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v2) {
        vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2[2U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v2;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v3) {
        vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2[3U] 
            = vlTOPp->__Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v3;
    }
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__83(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__83\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                      [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1)))));
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__84(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__84\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                      [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1)))));
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__85(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__85\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                      [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1)))));
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__86(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__86\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RG_valid_a1) 
           & (0U == vlTOPp->top__DOT__RingStop_RG_dest_a1
              [0U]));
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RG_valid_a1) 
           & (1U == vlTOPp->top__DOT__RingStop_RG_dest_a1
              [1U]));
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RG_valid_a1) 
           & (2U == vlTOPp->top__DOT__RingStop_RG_dest_a1
              [2U]));
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RG_valid_a1) 
           & (3U == vlTOPp->top__DOT__RingStop_RG_dest_a1
              [3U]));
    vlTOPp->top__DOT__RingStop_RG_pass_on_a1[0U] = 
        ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RG_valid_a1) 
         & (~ (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a1)));
    vlTOPp->top__DOT__RingStop_RG_pass_on_a1[1U] = 
        ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RG_valid_a1) 
         & (~ (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a1)));
    vlTOPp->top__DOT__RingStop_RG_pass_on_a1[2U] = 
        ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RG_valid_a1) 
         & (~ (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a1)));
    vlTOPp->top__DOT__RingStop_RG_pass_on_a1[3U] = 
        ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RG_valid_a1) 
         & (~ (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a1)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__87(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__87\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                      [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1)))));
    vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a0[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1)))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__88(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__88\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1)))));
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[3U];
    }
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__89(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__89\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1)))));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[3U];
    }
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__90(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__90\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1)))));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[3U];
    }
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__91(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__91\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1)))));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[3U];
    }
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__92(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__92\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                       << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                          << 3U)))) 
                 >> 5U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((3U == (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)
            ? 0U : (0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1) 
                                + (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a1) 
                                    & (~ (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                << 4U) 
                                               | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                   << 2U) 
                                                  | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                      << 1U) 
                                                     | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                            : (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                << 5U) 
                                               | (0x18U 
                                                  & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                     << 3U)))) 
                                          >> 2U))) ? 1U
                                    : 0U)) - (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_avail_a1) 
                                               & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_a1))
                                               ? 1U
                                               : 0U))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__93(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__93\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (1U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                             << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                << 2U))))) 
                 >> 5U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((3U == (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)
            ? 0U : (0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1) 
                                + (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a1) 
                                    & (~ (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                << 4U) 
                                               | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                   << 2U) 
                                                  | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                      << 1U) 
                                                     | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                            : (1U | 
                                               (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                 << 5U) 
                                                | (0x18U 
                                                   & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                      << 2U))))) 
                                          >> 2U))) ? 1U
                                    : 0U)) - (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_avail_a1) 
                                               & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_a1))
                                               ? 1U
                                               : 0U))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__94(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__94\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (2U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                             << 5U) | (0x18U & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                << 1U))))) 
                 >> 5U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((3U == (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)
            ? 0U : (0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1) 
                                + (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a1) 
                                    & (~ (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                << 4U) 
                                               | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                   << 2U) 
                                                  | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                      << 1U) 
                                                     | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                            : (2U | 
                                               (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                 << 5U) 
                                                | (0x18U 
                                                   & (vlTOPp->top__DOT__RW_rand_vect[0U] 
                                                      << 1U))))) 
                                          >> 2U))) ? 1U
                                    : 0U)) - (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_avail_a1) 
                                               & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_a1))
                                               ? 1U
                                               : 0U))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__95(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__95\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                   ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                       << 4U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                  << 2U) | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                             << 1U) 
                                            | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                   : (3U | (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                             << 5U) | (0x18U & vlTOPp->top__DOT__RW_rand_vect[0U])))) 
                 >> 5U));
    vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((3U == (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)
            ? 0U : (0xffffU & (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1) 
                                + (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a1) 
                                    & (~ (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1)
                                            ? (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1) 
                                                << 4U) 
                                               | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1) 
                                                   << 2U) 
                                                  | (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1) 
                                                      << 1U) 
                                                     | (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1))))
                                            : (3U | 
                                               (((IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1) 
                                                 << 5U) 
                                                | (0x18U 
                                                   & vlTOPp->top__DOT__RW_rand_vect[0U])))) 
                                          >> 2U))) ? 1U
                                    : 0U)) - (((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_avail_a1) 
                                               & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_a1))
                                               ? 1U
                                               : 0U))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__96(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__96\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp55[4];
    WData/*127:0*/ __Vtemp56[4];
    WData/*127:0*/ __Vtemp57[4];
    WData/*127:0*/ __Vtemp58[4];
    // Body
    VL_EXTEND_WI(100,5, __Vtemp55, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [0U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[0U] 
        = __Vtemp55[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[1U] 
        = __Vtemp55[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[2U] 
        = __Vtemp55[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[3U] 
        = __Vtemp55[3U];
    VL_EXTEND_WI(100,5, __Vtemp56, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [1U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[0U] 
        = __Vtemp56[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[1U] 
        = __Vtemp56[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[2U] 
        = __Vtemp56[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[3U] 
        = __Vtemp56[3U];
    VL_EXTEND_WI(100,5, __Vtemp57, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [2U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[0U] 
        = __Vtemp57[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[1U] 
        = __Vtemp57[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[2U] 
        = __Vtemp57[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[3U] 
        = __Vtemp57[3U];
    VL_EXTEND_WI(100,5, __Vtemp58, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [3U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[0U] 
        = __Vtemp58[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[1U] 
        = __Vtemp58[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[2U] 
        = __Vtemp58[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[3U] 
        = __Vtemp58[3U];
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1)))));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[3U];
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1)))));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[3U];
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1)))));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[3U];
    }
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt) 
                        >> 1U)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (~ (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one) 
           & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1) 
           & (~ ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero) 
                 | ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one) 
                    & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1)))));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1) 
           & (~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one)));
    if (vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero) {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[3U];
    } else {
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[0U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[0U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[1U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[1U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[2U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[2U];
        vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[3U] 
            = vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[3U];
    }
    vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1[0U] 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[0U] 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1[1U] 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[0U] 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1[2U] 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[0U] 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1[3U] 
        = (1U & (vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[0U] 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__97(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__97\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1[0U] 
        = (1U & ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                  [3U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                           [3U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                          [3U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                    [0U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1))) 
                 >> 2U));
    vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1[0U] 
        = (3U & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                 [3U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                          [3U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                         [3U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                   [0U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__98(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__98\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1[1U] 
        = (1U & ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                  [0U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                           [0U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                          [0U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                    [1U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1))) 
                 >> 2U));
    vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1[1U] 
        = (3U & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                 [0U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                          [0U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                         [0U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                   [1U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__99(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__99\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1[2U] 
        = (1U & ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                  [1U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                           [1U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                          [1U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                    [2U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1))) 
                 >> 2U));
    vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1[2U] 
        = (3U & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                 [1U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                          [1U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                         [1U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                   [2U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__100(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__100\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a1[3U] 
        = (1U & ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                  [2U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                           [2U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                          [2U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                    [3U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1))) 
                 >> 2U));
    vlTOPp->top__DOT__RingStop_RG_Trans_sender_a1[3U] 
        = (3U & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                 [2U] ? ((vlTOPp->top__DOT__RingStop_RG_Trans_cyc_cnt_a2
                          [2U] << 2U) | vlTOPp->top__DOT__RingStop_RG_Trans_sender_a2
                         [2U]) : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                   [3U] << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1))));
}

VL_INLINE_OPT void Vtop::_combo__TOP__101(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__101\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = (3U & ((0U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]))
                  ? vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]
                  : (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = (3U & ((1U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]))
                  ? vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]
                  : (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = (3U & ((2U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]))
                  ? vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]
                  : (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = (3U & ((3U != (3U & vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]))
                  ? vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]
                  : (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1)));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__102(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__102\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [0U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                      [0U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]))));
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [0U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__103(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__103\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [1U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                      [1U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]))));
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [1U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__104(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__104\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [2U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                      [2U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]))));
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [2U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__105(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__105\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a0 
        = (3U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [3U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]))) 
                 >> 2U));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a0 
        = (3U & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1)
                  ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                      [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1)))
                  : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                      [3U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]))));
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [3U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1)))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1)))) {
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1)))) {
        vlTOPp->_sequent__TOP__14(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1)))) {
        vlTOPp->_sequent__TOP__15(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9)))) {
        vlTOPp->_sequent__TOP__16(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9)))) {
        vlTOPp->_sequent__TOP__17(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9)))) {
        vlTOPp->_sequent__TOP__18(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9)))) {
        vlTOPp->_sequent__TOP__19(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__20(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__21(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__22(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__23(vlSymsp);
    }
    if ((((((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5))))) {
        vlTOPp->_sequent__TOP__28(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3)))) {
        vlTOPp->_sequent__TOP__29(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3)))) {
        vlTOPp->_sequent__TOP__30(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3)))) {
        vlTOPp->_sequent__TOP__31(vlSymsp);
        vlTOPp->__Vm_traceActivity[5U] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3)))) {
        vlTOPp->_sequent__TOP__32(vlSymsp);
        vlTOPp->__Vm_traceActivity[6U] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13)))) {
        vlTOPp->_sequent__TOP__33(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13)))) {
        vlTOPp->_sequent__TOP__34(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13)))) {
        vlTOPp->_sequent__TOP__35(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13)))) {
        vlTOPp->_sequent__TOP__36(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15)))) {
        vlTOPp->_sequent__TOP__37(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15)))) {
        vlTOPp->_sequent__TOP__38(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15)))) {
        vlTOPp->_sequent__TOP__39(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15)))) {
        vlTOPp->_sequent__TOP__40(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17)))) {
        vlTOPp->_sequent__TOP__41(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17)))) {
        vlTOPp->_sequent__TOP__42(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17)))) {
        vlTOPp->_sequent__TOP__43(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17)))) {
        vlTOPp->_sequent__TOP__44(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8)))) {
        vlTOPp->_sequent__TOP__45(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8)))) {
        vlTOPp->_sequent__TOP__46(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8)))) {
        vlTOPp->_sequent__TOP__47(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8)))) {
        vlTOPp->_sequent__TOP__48(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5)))) {
        vlTOPp->_sequent__TOP__49(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5)))) {
        vlTOPp->_sequent__TOP__50(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5)))) {
        vlTOPp->_sequent__TOP__51(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5)))) {
        vlTOPp->_sequent__TOP__52(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__53(vlSymsp);
        vlTOPp->__Vm_traceActivity[7U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__54(vlSymsp);
        vlTOPp->__Vm_traceActivity[8U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__55(vlSymsp);
        vlTOPp->__Vm_traceActivity[9U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__56(vlSymsp);
        vlTOPp->__Vm_traceActivity[0xaU] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__57(vlSymsp);
        vlTOPp->__Vm_traceActivity[0xbU] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__58(vlSymsp);
        vlTOPp->__Vm_traceActivity[0xcU] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__59(vlSymsp);
        vlTOPp->__Vm_traceActivity[0xdU] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__60(vlSymsp);
        vlTOPp->__Vm_traceActivity[0xeU] = 1U;
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__61(vlSymsp);
        vlTOPp->__Vm_traceActivity[0xfU] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__62(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__63(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x10U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__64(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__65(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x11U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__66(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19)))) {
        vlTOPp->_sequent__TOP__67(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x12U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__68(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__69(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x13U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15))))) {
        vlTOPp->_multiclk__TOP__70(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15))))) {
        vlTOPp->_multiclk__TOP__71(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15))))) {
        vlTOPp->_multiclk__TOP__72(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15))))) {
        vlTOPp->_multiclk__TOP__73(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__74(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__75(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__76(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__77(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7)))) {
        vlTOPp->_sequent__TOP__78(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7)))) {
        vlTOPp->_sequent__TOP__79(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7)))) {
        vlTOPp->_sequent__TOP__80(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7)))) {
        vlTOPp->_sequent__TOP__81(vlSymsp);
    }
    if ((((((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5))))) {
        vlTOPp->_sequent__TOP__82(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x14U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__83(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__84(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__85(vlSymsp);
    }
    if (((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__86(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x15U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__87(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__88(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x16U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__89(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x17U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__90(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x18U] = 1U;
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9))))) {
        vlTOPp->_multiclk__TOP__91(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x19U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__92(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__93(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__94(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19))))) {
        vlTOPp->_multiclk__TOP__95(vlSymsp);
    }
    if (((((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
                | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
                   & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15)))) 
               | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17) 
                  & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17)))) 
              | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
                 & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15)))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__96(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x1aU] = 1U;
    }
    if ((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5))))) {
        vlTOPp->_multiclk__TOP__97(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x1bU] = 1U;
    }
    if ((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5))))) {
        vlTOPp->_multiclk__TOP__98(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x1cU] = 1U;
    }
    if ((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5))))) {
        vlTOPp->_multiclk__TOP__99(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x1dU] = 1U;
    }
    if ((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5))))) {
        vlTOPp->_multiclk__TOP__100(vlSymsp);
        vlTOPp->__Vm_traceActivity[0x1eU] = 1U;
    }
    vlTOPp->_combo__TOP__101(vlSymsp);
    if (((((((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
                  | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1) 
                     & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1)))) 
                 | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
                    & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15)))) 
                | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17) 
                   & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17)))) 
               | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3) 
                  & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3)))) 
              | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
                 & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15)))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__102(vlSymsp);
    }
    if (((((((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
                  | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
                     & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15)))) 
                 | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17) 
                    & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17)))) 
                | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1) 
                   & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1)))) 
               | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
                  & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15)))) 
              | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17) 
                 & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17)))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__103(vlSymsp);
    }
    if (((((((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
                  | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
                     & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15)))) 
                 | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17) 
                    & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17)))) 
                | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
                   & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15)))) 
               | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17) 
                  & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17)))) 
              | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1) 
                 & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1)))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17))))) {
        vlTOPp->_multiclk__TOP__104(vlSymsp);
    }
    if (((((((((((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
                  | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15) 
                     & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15)))) 
                 | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17) 
                    & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17)))) 
                | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15) 
                   & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15)))) 
               | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17) 
                  & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17)))) 
              | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15) 
                 & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15)))) 
             | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17) 
                & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17)))) 
            | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1) 
               & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1)))) 
           | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15)))) 
          | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17)))) 
         | ((IData)(vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3))))) {
        vlTOPp->_multiclk__TOP__105(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19 
        = vlTOPp->top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17;
    vlTOPp->__Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17 
        = vlTOPp->top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1)
         | (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1)
         | (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1)
         | (vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1))) VL_DBG_MSGF("        CHANGE: /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv:1324: top.L1_Tb_RingStop[0].L1_RECEIVE1_Trans_dest_a1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1))) VL_DBG_MSGF("        CHANGE: /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv:1324: top.L1_Tb_RingStop[1].L1_RECEIVE1_Trans_dest_a1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1))) VL_DBG_MSGF("        CHANGE: /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv:1324: top.L1_Tb_RingStop[2].L1_RECEIVE1_Trans_dest_a1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1 ^ vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1))) VL_DBG_MSGF("        CHANGE: /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv:1324: top.L1_Tb_RingStop[3].L1_RECEIVE1_Trans_dest_a1\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
    vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
    vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
    vlTOPp->__Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1 
        = vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
