// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibon.h for the primary calling header

#include "Vfibon.h"
#include "Vfibon__Syms.h"

//==========

VL_CTOR_IMP(Vfibon) {
    Vfibon__Syms* __restrict vlSymsp = __VlSymsp = new Vfibon__Syms(this, name());
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfibon::__Vconfigure(Vfibon__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfibon::~Vfibon() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vfibon::_eval_initial(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_eval_initial\n"); );
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vfibon::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::final\n"); );
    // Variables
    Vfibon__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfibon::_eval_settle(Vfibon__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_eval_settle\n"); );
    Vfibon* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfibon::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibon::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    cyc_cnt = VL_RAND_RESET_I(32);
    passed = VL_RAND_RESET_I(1);
    failed = VL_RAND_RESET_I(1);
}
