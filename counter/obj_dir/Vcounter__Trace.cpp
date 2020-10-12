// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcounter__Syms.h"


void Vcounter::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vcounter::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*319:0*/ __Vtemp28[10];
    WData/*287:0*/ __Vtemp36[9];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgWData(oldp+0,(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2),257);
            __Vtemp28[0U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U];
            __Vtemp28[1U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U];
            __Vtemp28[2U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U];
            __Vtemp28[3U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U];
            __Vtemp28[4U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U];
            __Vtemp28[5U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U];
            __Vtemp28[6U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U];
            __Vtemp28[7U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U];
            __Vtemp28[8U] = ((0xfffffffeU & ((IData)(
                                                     (0x7fffffffffffffffULL 
                                                      & (((QData)((IData)(
                                                                          vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                             << 1U)) 
                             | vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U]);
            __Vtemp28[9U] = ((1U & ((IData)((0x7fffffffffffffffULL 
                                             & (((QData)((IData)(
                                                                 vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & ((IData)(
                                                             ((0x7fffffffffffffffULL 
                                                               & (((QData)((IData)(
                                                                                vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                                   << 0x20U) 
                                                                  | (QData)((IData)(
                                                                                vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U])))) 
                                                              >> 0x20U)) 
                                                     << 1U)));
            tracep->chgWData(oldp+9,(__Vtemp28),320);
            tracep->chgSData(oldp+19,(vlTOPp->top__DOT__L0_num_a1),16);
            if (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) {
                __Vtemp36[0U] = 0x4e4684aU;
                __Vtemp36[1U] = 0xc45f864U;
                __Vtemp36[2U] = 0x76874654U;
                __Vtemp36[3U] = 0xf3048b46U;
                __Vtemp36[4U] = 0x5cd84848U;
                __Vtemp36[5U] = 0x6684e132U;
                __Vtemp36[6U] = 0x713d5431U;
                __Vtemp36[7U] = 0x7163e168U;
                __Vtemp36[8U] = 0U;
            } else {
                __Vtemp36[0U] = ((0xfffffffeU & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                                 << 1U)) 
                                 ^ (0xc5U & (- (IData)(
                                                       (1U 
                                                        & vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U])))));
                __Vtemp36[1U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                                   << 1U)));
                __Vtemp36[2U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                                   << 1U)));
                __Vtemp36[3U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                                   << 1U)));
                __Vtemp36[4U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                                   << 1U)));
                __Vtemp36[5U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                                   << 1U)));
                __Vtemp36[6U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                                   << 1U)));
                __Vtemp36[7U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                        >> 0x1fU)) 
                                 | (0xfffffffeU & (
                                                   vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                                   << 1U)));
                __Vtemp36[8U] = (1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                       >> 0x1fU));
            }
            tracep->chgWData(oldp+20,(__Vtemp36),257);
            tracep->chgBit(oldp+29,(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1));
        }
        tracep->chgBit(oldp+30,(vlTOPp->clk));
        tracep->chgBit(oldp+31,(vlTOPp->reset));
        tracep->chgIData(oldp+32,(vlTOPp->cyc_cnt),32);
        tracep->chgBit(oldp+33,(vlTOPp->passed));
        tracep->chgBit(oldp+34,(vlTOPp->failed));
        tracep->chgSData(oldp+35,(((IData)(vlTOPp->reset)
                                    ? 0U : (0xffffU 
                                            & ((IData)(1U) 
                                               + (IData)(vlTOPp->top__DOT__L0_num_a1))))),16);
    }
}

void Vcounter::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
