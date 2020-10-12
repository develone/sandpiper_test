// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp10[4];
    WData/*127:0*/ __Vtemp11[4];
    WData/*127:0*/ __Vtemp12[4];
    WData/*127:0*/ __Vtemp13[4];
    WData/*127:0*/ __Vtemp14[4];
    WData/*127:0*/ __Vtemp15[4];
    WData/*127:0*/ __Vtemp16[4];
    WData/*127:0*/ __Vtemp17[4];
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
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_sender_a2)))) 
                 >> 4U));
    VL_EXTEND_WI(100,3, __Vtemp10, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [0U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[0U] 
        = __Vtemp10[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[1U] 
        = __Vtemp10[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[2U] 
        = __Vtemp10[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[3U] 
        = __Vtemp10[3U];
    VL_EXTEND_WI(100,3, __Vtemp11, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [1U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[0U] 
        = __Vtemp11[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[1U] 
        = __Vtemp11[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[2U] 
        = __Vtemp11[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[3U] 
        = __Vtemp11[3U];
    VL_EXTEND_WI(100,3, __Vtemp12, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [2U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[0U] 
        = __Vtemp12[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[1U] 
        = __Vtemp12[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[2U] 
        = __Vtemp12[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[3U] 
        = __Vtemp12[3U];
    VL_EXTEND_WI(100,3, __Vtemp13, ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4)
                                     ? (((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4) 
                                         << 2U) | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a4))
                                     : ((vlTOPp->top__DOT__RingStop_BP2_Trans_cyc_cnt_a1
                                         [3U] << 2U) 
                                        | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[0U] 
        = __Vtemp13[0U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[1U] 
        = __Vtemp13[1U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[2U] 
        = __Vtemp13[2U];
    vlTOPp->top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[3U] 
        = __Vtemp13[3U];
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_request_a1));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_request_a1));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_request_a1));
    vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1 
        = ((IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_request_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
           & (0U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
           & (1U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
           & (2U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BYPASS_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
           & (3U == (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
           & ((0U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
           & ((1U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
           & ((2U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_RING_IN_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
           & ((3U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1)) 
              | (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4)));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[0U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [3U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [3U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[1U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [0U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [0U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[2U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [1U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [1U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__RingStop_RG_dest_a1[3U] = (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
                                                 [2U]
                                                  ? 
                                                 vlTOPp->top__DOT__RingStop_RG_dest_a2
                                                 [2U]
                                                  : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [3U] | (0U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [0U] | (1U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [1U] | (2U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1 
        = ((vlTOPp->top__DOT__RingStop_RG_pass_on_a2
            [2U] | (3U != (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1))) 
           & (IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4));
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
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2)
                   ? ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a2)))
                   : ((vlTOPp->top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2)))) 
                 >> 4U));
    vlTOPp->top__DOT__Tb_COUNT_CycCount_a0 = ((IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_reset_a2)
                                               ? 0U
                                               : (0xffffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->top__DOT__Tb_COUNT_CycCount_a1))));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a2)));
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
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a2)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2)
               ? (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a2)
               : (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a2)));
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
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1 
        = ((IData)(vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BYPASS_avail_a1));
    vlTOPp->top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [3U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [0U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [1U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RG_valid_a1 
        = ((~ (IData)(vlTOPp->top__DOT__L0_reset_a1)) 
           & (vlTOPp->top__DOT__RingStop_RG_pass_on_a2
              [2U] | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_RING_IN_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1));
    VL_EXTEND_WI(100,5, __Vtemp14, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [0U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[0U] 
        = __Vtemp14[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[1U] 
        = __Vtemp14[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[2U] 
        = __Vtemp14[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[3U] 
        = __Vtemp14[3U];
    VL_EXTEND_WI(100,5, __Vtemp15, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [1U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[0U] 
        = __Vtemp15[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[1U] 
        = __Vtemp15[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[2U] 
        = __Vtemp15[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[3U] 
        = __Vtemp15[3U];
    VL_EXTEND_WI(100,5, __Vtemp16, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [2U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[0U] 
        = __Vtemp16[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[1U] 
        = __Vtemp16[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[2U] 
        = __Vtemp16[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[3U] 
        = __Vtemp16[3U];
    VL_EXTEND_WI(100,5, __Vtemp17, ((vlTOPp->top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1
                                     [3U] << 4U) | 
                                    (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a1) 
                                      << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a1))));
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[0U] 
        = __Vtemp17[0U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[1U] 
        = __Vtemp17[1U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[2U] 
        = __Vtemp17[2U];
    vlTOPp->top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[3U] 
        = __Vtemp17[3U];
    vlTOPp->passed = (0xfU == (IData)(vlTOPp->top__DOT__Tb_RingStop_PASSED_passed_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP0_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1));
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
    vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1));
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
    vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1));
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
    vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1));
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
    vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_FIFO2_OUT_avail_a1 
        = ((0U != (3U & (IData)(vlTOPp->top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt))) 
           | (IData)(vlTOPp->top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1));
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
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1));
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
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1));
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
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1));
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
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1 
        = ((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1) 
           & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1));
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
    vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP0_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP0_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP0_avail_a1)));
    vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a0 
        = ((~ (IData)(vlTOPp->top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1)) 
           & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1) 
               & (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1)) 
              | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP0_avail_a1)));
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
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[0U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [0U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [0U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[1U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [1U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [1U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[2U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [2U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [2U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
    vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[3U] 
        = (1U & (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1)
                   ? ((vlTOPp->top__DOT__RingStop_BP1_Trans_cyc_cnt_a1
                       [3U] << 4U) | (((IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1) 
                                       << 2U) | (IData)(vlTOPp->top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1)))
                   : ((vlTOPp->top__DOT__RingStop_BP0_Trans_cyc_cnt_a1
                       [3U] << 4U) | (0xfU & vlTOPp->top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[0U]))) 
                 >> 4U));
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[0x1eU] = 1U;
    vlTOPp->__Vm_traceActivity[0x1dU] = 1U;
    vlTOPp->__Vm_traceActivity[0x1cU] = 1U;
    vlTOPp->__Vm_traceActivity[0x1bU] = 1U;
    vlTOPp->__Vm_traceActivity[0x1aU] = 1U;
    vlTOPp->__Vm_traceActivity[0x19U] = 1U;
    vlTOPp->__Vm_traceActivity[0x18U] = 1U;
    vlTOPp->__Vm_traceActivity[0x17U] = 1U;
    vlTOPp->__Vm_traceActivity[0x16U] = 1U;
    vlTOPp->__Vm_traceActivity[0x15U] = 1U;
    vlTOPp->__Vm_traceActivity[0x14U] = 1U;
    vlTOPp->__Vm_traceActivity[0x13U] = 1U;
    vlTOPp->__Vm_traceActivity[0x12U] = 1U;
    vlTOPp->__Vm_traceActivity[0x11U] = 1U;
    vlTOPp->__Vm_traceActivity[0x10U] = 1U;
    vlTOPp->__Vm_traceActivity[0xfU] = 1U;
    vlTOPp->__Vm_traceActivity[0xeU] = 1U;
    vlTOPp->__Vm_traceActivity[0xdU] = 1U;
    vlTOPp->__Vm_traceActivity[0xcU] = 1U;
    vlTOPp->__Vm_traceActivity[0xbU] = 1U;
    vlTOPp->__Vm_traceActivity[0xaU] = 1U;
    vlTOPp->__Vm_traceActivity[9U] = 1U;
    vlTOPp->__Vm_traceActivity[8U] = 1U;
    vlTOPp->__Vm_traceActivity[7U] = 1U;
    vlTOPp->__Vm_traceActivity[6U] = 1U;
    vlTOPp->__Vm_traceActivity[5U] = 1U;
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    cyc_cnt = VL_RAND_RESET_I(32);
    passed = VL_RAND_RESET_I(1);
    failed = VL_RAND_RESET_I(1);
    VL_ZERO_RESET_W(320, top__DOT__RW_rand_vect);
    top__DOT__L0_reset_a1 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_BP0_Trans_cyc_cnt_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_BP1_Trans_cyc_cnt_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_BP2_Trans_cyc_cnt_a0[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_BP2_Trans_cyc_cnt_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_dest_a1[__Vi0] = VL_RAND_RESET_I(2);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_dest_a2[__Vi0] = VL_RAND_RESET_I(2);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_pass_on_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_pass_on_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_Trans_cyc_cnt_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_Trans_cyc_cnt_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_Trans_sender_a1[__Vi0] = VL_RAND_RESET_I(2);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_RG_Trans_sender_a2[__Vi0] = VL_RAND_RESET_I(2);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    top__DOT__Tb_RingStop_PASSED_passed_a1 = VL_RAND_RESET_I(4);
    top__DOT__Tb_COUNT_CycCount_a0 = VL_RAND_RESET_I(16);
    top__DOT__Tb_COUNT_CycCount_a1 = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_BP1_avail_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_BP2_avail_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_RG_valid_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_STALL0_avail_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_STALL1_avail_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_RingStop_STALL2_avail_a2[__Vi0] = VL_RAND_RESET_I(1);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1[__Vi0] = VL_RAND_RESET_I(1);
    }}
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19 = VL_RAND_RESET_I(1);
    top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BYPASS_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_RING_IN_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BYPASS_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_RING_IN_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BYPASS_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_RING_IN_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a0 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a0 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BYPASS_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_RING_IN_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RG_valid_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_trans_valid_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_trans_valid_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a3 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a4 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RG_valid_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_trans_valid_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_trans_valid_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a3 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a4 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RG_valid_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_trans_valid_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_trans_valid_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a3 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a4 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RG_valid_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_trans_valid_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_trans_valid_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4 = VL_RAND_RESET_I(1);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a3 = VL_RAND_RESET_I(2);
    top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a4 = VL_RAND_RESET_I(2);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_FIFO2_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_FIFO2_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_FIFO2_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_FIFO2_OUT_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt = VL_RAND_RESET_I(3);
    VL_RAND_RESET_W(100, top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out);
    VL_RAND_RESET_W(100, top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1 = VL_RAND_RESET_I(16);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1 = VL_RAND_RESET_I(2);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_request_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_sender_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_dest_a2 = VL_RAND_RESET_I(2);
    top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_sender_a2 = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(257, top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1);
    VL_RAND_RESET_W(257, top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2);
    top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head = VL_RAND_RESET_I(2);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[__Vi0]);
    }}
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out);
    VL_RAND_RESET_W(100, top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr = VL_RAND_RESET_I(1);
    top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr = VL_RAND_RESET_I(1);
    __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0 = VL_RAND_RESET_I(1);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0 = 0;
    __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v0 = VL_RAND_RESET_I(2);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v0 = 0;
    __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1 = VL_RAND_RESET_I(1);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1 = 0;
    __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v1 = VL_RAND_RESET_I(2);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v1 = 0;
    __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2 = VL_RAND_RESET_I(1);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2 = 0;
    __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v2 = VL_RAND_RESET_I(2);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v2 = 0;
    __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3 = VL_RAND_RESET_I(1);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3 = 0;
    __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v3 = VL_RAND_RESET_I(2);
    __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v3 = 0;
    __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1 = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<31; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
