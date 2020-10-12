// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcounter__Syms.h"


//======================

void Vcounter::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcounter::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcounter::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcounter::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcounter::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+31,"clk", false,-1);
        tracep->declBit(c+32,"reset", false,-1);
        tracep->declBus(c+33,"cyc_cnt", false,-1, 31,0);
        tracep->declBit(c+34,"passed", false,-1);
        tracep->declBit(c+35,"failed", false,-1);
        tracep->declBit(c+31,"top clk", false,-1);
        tracep->declBit(c+32,"top reset", false,-1);
        tracep->declBus(c+33,"top cyc_cnt", false,-1, 31,0);
        tracep->declBit(c+34,"top passed", false,-1);
        tracep->declBit(c+35,"top failed", false,-1);
        tracep->declArray(c+1,"top RW_rand_raw", false,-1, 256,0);
        tracep->declArray(c+10,"top RW_rand_vect", false,-1, 319,0);
        tracep->declBus(c+36,"top L0_num_a0", false,-1, 15,0);
        tracep->declBus(c+20,"top L0_num_a1", false,-1, 15,0);
        tracep->declBus(c+37,"top pseudo_rand WIDTH", false,-1, 31,0);
        tracep->declBit(c+31,"top pseudo_rand clk", false,-1);
        tracep->declBit(c+32,"top pseudo_rand reset", false,-1);
        tracep->declArray(c+1,"top pseudo_rand rand_vect", false,-1, 256,0);
        tracep->declBus(c+37,"top pseudo_rand LFSR_WIDTH", false,-1, 31,0);
        tracep->declArray(c+38,"top pseudo_rand LFSR_POLY", false,-1, 256,0);
        tracep->declArray(c+47,"top pseudo_rand SEED", false,-1, 256,0);
        tracep->declArray(c+21,"top pseudo_rand DEFAULT_lfsr_a1", false,-1, 256,0);
        tracep->declArray(c+1,"top pseudo_rand DEFAULT_lfsr_a2", false,-1, 256,0);
        tracep->declBit(c+32,"top pseudo_rand DEFAULT_reset_a0", false,-1);
        tracep->declBit(c+30,"top pseudo_rand DEFAULT_reset_a1", false,-1);
    }
}

void Vcounter::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcounter::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcounter::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*319:0*/ __Vtemp17[10];
    WData/*287:0*/ __Vtemp25[9];
    WData/*287:0*/ __Vtemp26[9];
    WData/*287:0*/ __Vtemp27[9];
    // Body
    {
        tracep->fullWData(oldp+1,(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2),257);
        __Vtemp17[0U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U];
        __Vtemp17[1U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U];
        __Vtemp17[2U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U];
        __Vtemp17[3U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U];
        __Vtemp17[4U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U];
        __Vtemp17[5U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U];
        __Vtemp17[6U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U];
        __Vtemp17[7U] = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U];
        __Vtemp17[8U] = ((0xfffffffeU & ((IData)((0x7fffffffffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                         << 1U)) | 
                         vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U]);
        __Vtemp17[9U] = ((1U & ((IData)((0x7fffffffffffffffULL 
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
        tracep->fullWData(oldp+10,(__Vtemp17),320);
        tracep->fullSData(oldp+20,(vlTOPp->top__DOT__L0_num_a1),16);
        if (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) {
            __Vtemp25[0U] = 0x4e4684aU;
            __Vtemp25[1U] = 0xc45f864U;
            __Vtemp25[2U] = 0x76874654U;
            __Vtemp25[3U] = 0xf3048b46U;
            __Vtemp25[4U] = 0x5cd84848U;
            __Vtemp25[5U] = 0x6684e132U;
            __Vtemp25[6U] = 0x713d5431U;
            __Vtemp25[7U] = 0x7163e168U;
            __Vtemp25[8U] = 0U;
        } else {
            __Vtemp25[0U] = ((0xfffffffeU & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                             << 1U)) 
                             ^ (0xc5U & (- (IData)(
                                                   (1U 
                                                    & vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U])))));
            __Vtemp25[1U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                                     << 1U)));
            __Vtemp25[2U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                                     << 1U)));
            __Vtemp25[3U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                                     << 1U)));
            __Vtemp25[4U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                                     << 1U)));
            __Vtemp25[5U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                                     << 1U)));
            __Vtemp25[6U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                                     << 1U)));
            __Vtemp25[7U] = ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                                     << 1U)));
            __Vtemp25[8U] = (1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                   >> 0x1fU));
        }
        tracep->fullWData(oldp+21,(__Vtemp25),257);
        tracep->fullBit(oldp+30,(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1));
        tracep->fullBit(oldp+31,(vlTOPp->clk));
        tracep->fullBit(oldp+32,(vlTOPp->reset));
        tracep->fullIData(oldp+33,(vlTOPp->cyc_cnt),32);
        tracep->fullBit(oldp+34,(vlTOPp->passed));
        tracep->fullBit(oldp+35,(vlTOPp->failed));
        tracep->fullSData(oldp+36,(((IData)(vlTOPp->reset)
                                     ? 0U : (0xffffU 
                                             & ((IData)(1U) 
                                                + (IData)(vlTOPp->top__DOT__L0_num_a1))))),16);
        tracep->fullIData(oldp+37,(0x101U),32);
        __Vtemp26[0U] = 0xc5U;
        __Vtemp26[1U] = 0U;
        __Vtemp26[2U] = 0U;
        __Vtemp26[3U] = 0U;
        __Vtemp26[4U] = 0U;
        __Vtemp26[5U] = 0U;
        __Vtemp26[6U] = 0U;
        __Vtemp26[7U] = 0U;
        __Vtemp26[8U] = 0U;
        tracep->fullWData(oldp+38,(__Vtemp26),257);
        __Vtemp27[0U] = 0x4e4684aU;
        __Vtemp27[1U] = 0xc45f864U;
        __Vtemp27[2U] = 0x76874654U;
        __Vtemp27[3U] = 0xf3048b46U;
        __Vtemp27[4U] = 0x5cd84848U;
        __Vtemp27[5U] = 0x6684e132U;
        __Vtemp27[6U] = 0x713d5431U;
        __Vtemp27[7U] = 0x7163e168U;
        __Vtemp27[8U] = 0U;
        tracep->fullWData(oldp+47,(__Vtemp27),257);
    }
}
