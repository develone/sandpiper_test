// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmakerchip__Syms.h"


void Vmakerchip::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vmakerchip::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*319:0*/ __Vtemp29[10];
    WData/*287:0*/ __Vtemp37[9];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->makerchip__DOT__reset));
            tracep->chgIData(oldp+1,(vlTOPp->makerchip__DOT__cyc_cnt),32);
            tracep->chgWData(oldp+2,(vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2),257);
            __Vtemp29[0U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U];
            __Vtemp29[1U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U];
            __Vtemp29[2U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U];
            __Vtemp29[3U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U];
            __Vtemp29[4U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U];
            __Vtemp29[5U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U];
            __Vtemp29[6U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U];
            __Vtemp29[7U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U];
            __Vtemp29[8U] = ((0xfffffffeU & ((IData)(
                                                     (0x7fffffffffffffffULL 
                                                      & (((QData)((IData)(
                                                                          vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                             << 1U)) 
                             | vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U]);
            __Vtemp29[9U] = ((1U & ((IData)((0x7fffffffffffffffULL 
                                             & (((QData)((IData)(
                                                                 vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & ((IData)(
                                                             ((0x7fffffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                                   << 0x20U) 
                                                                  | (QData)((IData)(
                                                                                vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U])))) 
                                                              >> 0x20U)) 
                                                     << 1U)));
            tracep->chgWData(oldp+11,(__Vtemp29),320);
            if (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) {
                __Vtemp37[0U] = 0x4e4684aU;
                __Vtemp37[1U] = 0xc45f864U;
                __Vtemp37[2U] = 0x76874654U;
                __Vtemp37[3U] = 0xf3048b46U;
                __Vtemp37[4U] = 0x5cd84848U;
                __Vtemp37[5U] = 0x6684e132U;
                __Vtemp37[6U] = 0x713d5431U;
                __Vtemp37[7U] = 0x7163e168U;
                __Vtemp37[8U] = 0U;
            } else {
                __Vtemp37[0U] = ((0xfffffffeU & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                                 << 1U)) 
                                 ^ (0xc5U & (- (IData)(
                                                       (1U 
                                                        & vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U])))));
                __Vtemp37[1U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                                   << 1U)));
                __Vtemp37[2U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                                   << 1U)));
                __Vtemp37[3U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                                   << 1U)));
                __Vtemp37[4U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                                   << 1U)));
                __Vtemp37[5U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                                   << 1U)));
                __Vtemp37[6U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                                   << 1U)));
                __Vtemp37[7U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                                   << 1U)));
                __Vtemp37[8U] = (1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                       >> 0x1fU));
            }
            tracep->chgWData(oldp+21,(__Vtemp37),257);
            tracep->chgBit(oldp+30,(vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1));
        }
        tracep->chgBit(oldp+31,(vlTOPp->clk));
        tracep->chgBit(oldp+32,(vlTOPp->reset_async));
        tracep->chgBit(oldp+33,(vlTOPp->passed));
        tracep->chgBit(oldp+34,(vlTOPp->failed));
    }
}

void Vmakerchip::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
