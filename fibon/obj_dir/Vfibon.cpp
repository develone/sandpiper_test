// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibon.h for the primary calling header

#include "Vfibon.h"
#include "Vfibon__Syms.h"

//==========

void Vfibon::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfibon::eval\n"); );
    Vfibon__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("top.tlv", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfibon::_eval_initial_loop(Vfibon__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("top.tlv", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfibon::_sequent__TOP__1(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_sequent__TOP__1\n"); );
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1 
        = vlTOPp->reset;
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
    vlTOPp->top__DOT__L0_num_a2 = vlTOPp->top__DOT__L0_num_a1;
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
    vlTOPp->top__DOT__L0_num_a1 = vlTOPp->top__DOT__L0_num_a0;
}

VL_INLINE_OPT void Vfibon::_combo__TOP__3(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_combo__TOP__3\n"); );
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__L0_num_a0 = ((IData)(vlTOPp->reset)
                                    ? 1U : (0xffffU 
                                            & ((IData)(vlTOPp->top__DOT__L0_num_a1) 
                                               + (IData)(vlTOPp->top__DOT__L0_num_a2))));
}

void Vfibon::_eval(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_eval\n"); );
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vfibon::_change_request(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_change_request\n"); );
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfibon::_change_request_1(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_change_request_1\n"); );
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
#endif  // VL_DEBUG
