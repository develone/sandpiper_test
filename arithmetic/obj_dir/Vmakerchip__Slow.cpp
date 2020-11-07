// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmakerchip.h for the primary calling header

#include "Vmakerchip.h"
#include "Vmakerchip__Syms.h"

//==========

VL_CTOR_IMP(Vmakerchip) {
    Vmakerchip__Syms* __restrict vlSymsp = __VlSymsp = new Vmakerchip__Syms(this, name());
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmakerchip::__Vconfigure(Vmakerchip__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vmakerchip::~Vmakerchip() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vmakerchip::_settle__TOP__2(Vmakerchip__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_settle__TOP__2\n"); );
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) {
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U] = 0x4e4684aU;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U] = 0xc45f864U;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U] = 0x76874654U;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U] = 0xf3048b46U;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U] = 0x5cd84848U;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U] = 0x6684e132U;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U] = 0x713d5431U;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U] = 0x7163e168U;
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U] = 0U;
    } else {
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U] 
            = ((0xfffffffeU & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                               << 1U)) ^ (0xc5U & (- (IData)(
                                                             (1U 
                                                              & vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U])))));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U] 
            = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                                   << 1U)));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U] 
            = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                                   << 1U)));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U] 
            = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                                   << 1U)));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U] 
            = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                                   << 1U)));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U] 
            = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                                   << 1U)));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U] 
            = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                                   << 1U)));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U] 
            = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                      >> 0x1fU)) | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                                   << 1U)));
        vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U] 
            = (1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                     >> 0x1fU));
    }
}

void Vmakerchip::_eval_initial(Vmakerchip__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_eval_initial\n"); );
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmakerchip::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::final\n"); );
    // Variables
    Vmakerchip__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmakerchip::_eval_settle(Vmakerchip__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_eval_settle\n"); );
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vmakerchip::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_async = VL_RAND_RESET_I(1);
    passed = VL_RAND_RESET_I(1);
    failed = VL_RAND_RESET_I(1);
    makerchip__DOT__reset = VL_RAND_RESET_I(1);
    makerchip__DOT__cyc_cnt = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(257, makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1);
    VL_RAND_RESET_W(257, makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2);
    makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
