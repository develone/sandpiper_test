// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmakerchip__Syms.h"


//======================

void Vmakerchip::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vmakerchip::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmakerchip::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vmakerchip::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vmakerchip::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+32,"clk", false,-1);
        tracep->declBit(c+33,"reset_async", false,-1);
        tracep->declBit(c+34,"passed", false,-1);
        tracep->declBit(c+35,"failed", false,-1);
        tracep->declBit(c+32,"makerchip clk", false,-1);
        tracep->declBit(c+33,"makerchip reset_async", false,-1);
        tracep->declBit(c+34,"makerchip passed", false,-1);
        tracep->declBit(c+35,"makerchip failed", false,-1);
        tracep->declBit(c+1,"makerchip reset", false,-1);
        tracep->declBus(c+2,"makerchip cyc_cnt", false,-1, 31,0);
        tracep->declBit(c+32,"makerchip top clk", false,-1);
        tracep->declBit(c+1,"makerchip top reset", false,-1);
        tracep->declBus(c+2,"makerchip top cyc_cnt", false,-1, 31,0);
        tracep->declBit(c+34,"makerchip top passed", false,-1);
        tracep->declBit(c+35,"makerchip top failed", false,-1);
        tracep->declArray(c+3,"makerchip top RW_rand_raw", false,-1, 256,0);
        tracep->declArray(c+12,"makerchip top RW_rand_vect", false,-1, 319,0);
        tracep->declBus(c+36,"makerchip top L0_num1_a0", false,-1, 3,0);
        tracep->declBus(c+36,"makerchip top L0_num2_a0", false,-1, 3,0);
        tracep->declBus(c+37,"makerchip top L0_out_a0", false,-1, 7,0);
        tracep->declBus(c+36,"makerchip top DEBUG_SIGS @0$num1", false,-1, 3,0);
        tracep->declBus(c+36,"makerchip top DEBUG_SIGS @0$num2", false,-1, 3,0);
        tracep->declBus(c+37,"makerchip top DEBUG_SIGS @0$out", false,-1, 7,0);
        tracep->declBus(c+38,"makerchip top pseudo_rand WIDTH", false,-1, 31,0);
        tracep->declBit(c+32,"makerchip top pseudo_rand clk", false,-1);
        tracep->declBit(c+1,"makerchip top pseudo_rand reset", false,-1);
        tracep->declArray(c+3,"makerchip top pseudo_rand rand_vect", false,-1, 256,0);
        tracep->declBus(c+38,"makerchip top pseudo_rand LFSR_WIDTH", false,-1, 31,0);
        tracep->declArray(c+39,"makerchip top pseudo_rand LFSR_POLY", false,-1, 256,0);
        tracep->declArray(c+48,"makerchip top pseudo_rand SEED", false,-1, 256,0);
        tracep->declArray(c+22,"makerchip top pseudo_rand DEFAULT_lfsr_a1", false,-1, 256,0);
        tracep->declArray(c+3,"makerchip top pseudo_rand DEFAULT_lfsr_a2", false,-1, 256,0);
        tracep->declBit(c+1,"makerchip top pseudo_rand DEFAULT_reset_a0", false,-1);
        tracep->declBit(c+31,"makerchip top pseudo_rand DEFAULT_reset_a1", false,-1);
    }
}

void Vmakerchip::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vmakerchip::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vmakerchip::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vmakerchip__Syms* __restrict vlSymsp = static_cast<Vmakerchip__Syms*>(userp);
    Vmakerchip* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*319:0*/ __Vtemp18[10];
    WData/*287:0*/ __Vtemp26[9];
    WData/*287:0*/ __Vtemp27[9];
    WData/*287:0*/ __Vtemp28[9];
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->makerchip__DOT__reset));
        tracep->fullIData(oldp+2,(vlTOPp->makerchip__DOT__cyc_cnt),32);
        tracep->fullWData(oldp+3,(vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2),257);
        __Vtemp18[0U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U];
        __Vtemp18[1U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U];
        __Vtemp18[2U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U];
        __Vtemp18[3U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U];
        __Vtemp18[4U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U];
        __Vtemp18[5U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U];
        __Vtemp18[6U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U];
        __Vtemp18[7U] = vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U];
        __Vtemp18[8U] = ((0xfffffffeU & ((IData)((0x7fffffffffffffffULL 
                                                  & (((QData)((IData)(
                                                                      vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U])) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]))))) 
                                         << 1U)) | 
                         vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U]);
        __Vtemp18[9U] = ((1U & ((IData)((0x7fffffffffffffffULL 
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
        tracep->fullWData(oldp+12,(__Vtemp18),320);
        if (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) {
            __Vtemp26[0U] = 0x4e4684aU;
            __Vtemp26[1U] = 0xc45f864U;
            __Vtemp26[2U] = 0x76874654U;
            __Vtemp26[3U] = 0xf3048b46U;
            __Vtemp26[4U] = 0x5cd84848U;
            __Vtemp26[5U] = 0x6684e132U;
            __Vtemp26[6U] = 0x713d5431U;
            __Vtemp26[7U] = 0x7163e168U;
            __Vtemp26[8U] = 0U;
        } else {
            __Vtemp26[0U] = ((0xfffffffeU & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                             << 1U)) 
                             ^ (0xc5U & (- (IData)(
                                                   (1U 
                                                    & vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U])))));
            __Vtemp26[1U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                                     << 1U)));
            __Vtemp26[2U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                                     << 1U)));
            __Vtemp26[3U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                                     << 1U)));
            __Vtemp26[4U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                                     << 1U)));
            __Vtemp26[5U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                                     << 1U)));
            __Vtemp26[6U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                                     << 1U)));
            __Vtemp26[7U] = ((1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
                                    >> 0x1fU)) | (0xfffffffeU 
                                                  & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                                     << 1U)));
            __Vtemp26[8U] = (1U & (vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
                                   >> 0x1fU));
        }
        tracep->fullWData(oldp+22,(__Vtemp26),257);
        tracep->fullBit(oldp+31,(vlTOPp->makerchip__DOT__top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1));
        tracep->fullBit(oldp+32,(vlTOPp->clk));
        tracep->fullBit(oldp+33,(vlTOPp->reset_async));
        tracep->fullBit(oldp+34,(vlTOPp->passed));
        tracep->fullBit(oldp+35,(vlTOPp->failed));
        tracep->fullCData(oldp+36,(0U),4);
        tracep->fullCData(oldp+37,(0xffU),8);
        tracep->fullIData(oldp+38,(0x101U),32);
        __Vtemp27[0U] = 0xc5U;
        __Vtemp27[1U] = 0U;
        __Vtemp27[2U] = 0U;
        __Vtemp27[3U] = 0U;
        __Vtemp27[4U] = 0U;
        __Vtemp27[5U] = 0U;
        __Vtemp27[6U] = 0U;
        __Vtemp27[7U] = 0U;
        __Vtemp27[8U] = 0U;
        tracep->fullWData(oldp+39,(__Vtemp27),257);
        __Vtemp28[0U] = 0x4e4684aU;
        __Vtemp28[1U] = 0xc45f864U;
        __Vtemp28[2U] = 0x76874654U;
        __Vtemp28[3U] = 0xf3048b46U;
        __Vtemp28[4U] = 0x5cd84848U;
        __Vtemp28[5U] = 0x6684e132U;
        __Vtemp28[6U] = 0x713d5431U;
        __Vtemp28[7U] = 0x7163e168U;
        __Vtemp28[8U] = 0U;
        tracep->fullWData(oldp+48,(__Vtemp28),257);
    }
}
