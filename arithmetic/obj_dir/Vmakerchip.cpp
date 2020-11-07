// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmakerchip.h for the primary calling header

#include "Vmakerchip.h"
#include "Vmakerchip__Syms.h"

//==========

void Vmakerchip::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmakerchip::eval\n"); );
    Vmakerchip__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("makerchip.sv", 13, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmakerchip::_eval_initial_loop(Vmakerchip__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("makerchip.sv", 13, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vmakerchip::_sequent__TOP__1(Vmakerchip__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_sequent__TOP__1\n"); );
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->makerchip__DOT__cyc_cnt = ((IData)(vlTOPp->makerchip__DOT__reset)
                                        ? 1U : ((IData)(1U) 
                                                + vlTOPp->makerchip__DOT__cyc_cnt));
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U] 
        = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U];
    vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1 
        = vlTOPp->makerchip__DOT__reset;
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
    vlTOPp->makerchip__DOT__reset = vlTOPp->reset_async;
}

void Vmakerchip::_eval(Vmakerchip__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_eval\n"); );
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vmakerchip::_change_request(Vmakerchip__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_change_request\n"); );
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vmakerchip::_change_request_1(Vmakerchip__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_change_request_1\n"); );
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmakerchip::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmakerchip::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_async & 0xfeU))) {
        Verilated::overWidthError("reset_async");}
}
#endif  // VL_DEBUG
