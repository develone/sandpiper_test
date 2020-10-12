// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(passed,0,0);
    VL_OUT8(failed,0,0);
    VL_IN(cyc_cnt,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__L0_reset_a1;
        CData/*3:0*/ top__DOT__Tb_RingStop_PASSED_passed_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP0_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP1_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_blocked_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BP2_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_BYPASS_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_RING_IN_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL1_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__L1_STALL2_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP0_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP1_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_blocked_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BP2_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_BYPASS_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_RING_IN_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL1_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a1;
    };
    struct {
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__L1_STALL2_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP0_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP1_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_blocked_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BP2_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_BYPASS_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_RING_IN_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL1_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__L1_STALL2_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP0_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP1_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a0;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_blocked_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_recirc_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a0;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BP2_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_BYPASS_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_RING_IN_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a1;
    };
    struct {
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL1_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a1;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_avail_a2;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_blocked_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__L1_STALL2_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RG_valid_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_avail_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_reset_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_trans_valid_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_trans_valid_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a2;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a3;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__0__KET____DOT__L1_RING_OUT_Trans_sender_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RG_valid_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_avail_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_reset_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_trans_valid_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_trans_valid_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a2;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a3;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__1__KET____DOT__L1_RING_OUT_Trans_sender_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RG_valid_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_avail_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_reset_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_trans_valid_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_trans_valid_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a2;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a3;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__2__KET____DOT__L1_RING_OUT_Trans_sender_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RG_valid_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_avail_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a2;
    };
    struct {
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_reset_a4;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_trans_valid_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_trans_valid_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a2;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a3;
        CData/*0:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_cyc_cnt_a4;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a2;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a3;
        CData/*1:0*/ top__DOT__L1b_RingStop__BRA__3__KET____DOT__L1_RING_OUT_Trans_sender_a4;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_ARB_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__L1_FIFO2_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_ARB_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__L1_FIFO2_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_ARB_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__L1_FIFO2_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_ARB_OUT_avail_a1;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__L1_FIFO2_OUT_avail_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_avail_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_reset_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_valid_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_avail_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_reset_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_valid_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_avail_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_reset_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_valid_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_Trans_sender_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_avail_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_reset_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_valid_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_cyc_cnt_a1;
        CData/*1:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_dest_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_request_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_response_debug_a1;
        CData/*0:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_Trans_sender_a1;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a1;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_avail_a2;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_reset_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__0__KET____DOT__L1_STALL0_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a1;
    };
    struct {
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_avail_a2;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_reset_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__1__KET____DOT__L1_STALL0_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a1;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_avail_a2;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_reset_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__2__KET____DOT__L1_STALL0_Trans_sender_a2;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a1;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_avail_a2;
        CData/*0:0*/ top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_reset_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_dest_a2;
        CData/*1:0*/ top__DOT__L1e_RingStop__BRA__3__KET____DOT__L1_STALL0_Trans_sender_a2;
        CData/*0:0*/ top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_zero;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__popped_from_arr;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_zero;
    };
    struct {
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__popped_from_arr;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_zero;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__popped_from_arr;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__next_head;
        CData/*1:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__tail;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero_or_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_zero;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__cnt_one;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__push_head;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__pop_from_arr;
        CData/*0:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__popped_from_arr;
        SData/*15:0*/ top__DOT__Tb_COUNT_CycCount_a0;
        SData/*15:0*/ top__DOT__Tb_COUNT_CycCount_a1;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a0;
        SData/*15:0*/ top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE2_OutstandingPackets_a1;
        WData/*319:0*/ top__DOT__RW_rand_vect[10];
        WData/*256:0*/ top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[9];
        WData/*256:0*/ top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[9];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__head_data[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__head_data[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__head_data[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr_out[4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__head_data[4];
        CData/*0:0*/ top__DOT__RingStop_BP0_Trans_cyc_cnt_a1[4];
        CData/*0:0*/ top__DOT__RingStop_BP1_Trans_cyc_cnt_a0[4];
        CData/*0:0*/ top__DOT__RingStop_BP1_Trans_cyc_cnt_a1[4];
        CData/*0:0*/ top__DOT__RingStop_BP2_Trans_cyc_cnt_a0[4];
        CData/*0:0*/ top__DOT__RingStop_BP2_Trans_cyc_cnt_a1[4];
        CData/*1:0*/ top__DOT__RingStop_RG_dest_a1[4];
        CData/*1:0*/ top__DOT__RingStop_RG_dest_a2[4];
        CData/*0:0*/ top__DOT__RingStop_RG_pass_on_a1[4];
        CData/*0:0*/ top__DOT__RingStop_RG_pass_on_a2[4];
        CData/*0:0*/ top__DOT__RingStop_RG_Trans_cyc_cnt_a1[4];
        CData/*0:0*/ top__DOT__RingStop_RG_Trans_cyc_cnt_a2[4];
        CData/*1:0*/ top__DOT__RingStop_RG_Trans_sender_a1[4];
    };
    struct {
        CData/*1:0*/ top__DOT__RingStop_RG_Trans_sender_a2[4];
        CData/*0:0*/ top__DOT__RingStop_STALL0_Trans_cyc_cnt_a1[4];
        CData/*0:0*/ top__DOT__RingStop_STALL0_Trans_cyc_cnt_a2[4];
        CData/*0:0*/ top__DOT__RingStop_STALL1_Trans_cyc_cnt_a1[4];
        CData/*0:0*/ top__DOT__RingStop_STALL1_Trans_cyc_cnt_a2[4];
        CData/*0:0*/ top__DOT__RingStop_STALL2_Trans_cyc_cnt_a1[4];
        CData/*0:0*/ top__DOT__RingStop_STALL2_Trans_cyc_cnt_a2[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_BP1_avail_a1[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_BP2_avail_a1[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_RG_valid_a2[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_RING_OUT_trans_valid_a2[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_RING_OUT_trans_valid_a3[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_RING_OUT_trans_valid_a4[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_STALL0_avail_a2[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_STALL1_avail_a2[4];
        CData/*0:0*/ top__DOT__clkP_RingStop_STALL2_avail_a2[4];
        CData/*0:0*/ top__DOT__clkP_Tb_RingStop_RECEIVE2_avail_a1[4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[4][4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[4][4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[4][4];
        WData/*99:0*/ top__DOT__L1_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[4][4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__0__KET____DOT__fifo__DOT__arr[4][4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__1__KET____DOT__fifo__DOT__arr[4][4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__2__KET____DOT__fifo__DOT__arr[4][4];
        WData/*99:0*/ top__DOT__L1c_RingStop__BRA__3__KET____DOT__fifo__DOT__arr[4][4];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17;
        CData/*0:0*/ top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19;
        CData/*0:0*/ top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19;
        CData/*0:0*/ top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19;
        CData/*0:0*/ top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19;
        CData/*2:0*/ top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__cnt;
        CData/*2:0*/ top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__cnt;
        CData/*2:0*/ top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__cnt;
        CData/*2:0*/ top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__cnt;
        CData/*2:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__cnt;
        CData/*2:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__cnt;
        CData/*2:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__cnt;
        CData/*2:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__cnt;
        CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v0;
        CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v0;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v0;
        CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v1;
        CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v1;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v1;
        CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v2;
        CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v2;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v2;
        CData/*0:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_cyc_cnt_a2__v3;
        CData/*1:0*/ __Vdlyvval__top__DOT__RingStop_RG_Trans_sender_a2__v3;
        CData/*0:0*/ __Vdlyvset__top__DOT__RingStop_RG_Trans_sender_a2__v3;
    };
    struct {
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr7;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr8;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr1;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr9;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__0__KET____DOT____Vsenitemexpr19;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__1__KET____DOT____Vsenitemexpr19;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__2__KET____DOT____Vsenitemexpr19;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_Tb_RingStop__BRA__3__KET____DOT____Vsenitemexpr19;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr5;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr3;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr13;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr15;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__0__KET____DOT____Vsenitemexpr17;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__1__KET____DOT____Vsenitemexpr17;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__2__KET____DOT____Vsenitemexpr17;
        CData/*0:0*/ __Vclklast__TOP__top__DOT__L1gen_RingStop__BRA__3__KET____DOT____Vsenitemexpr17;
        CData/*1:0*/ __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__0__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        CData/*1:0*/ __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__1__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        CData/*1:0*/ __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__2__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        CData/*1:0*/ __Vchglast__TOP__top__DOT__L1_Tb_RingStop__BRA__3__KET____DOT__L1_RECEIVE1_Trans_dest_a1;
        WData/*99:0*/ top__DOT____Vcellout__L1_RingStop__BRA__0__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1_RingStop__BRA__0__KET____DOT__fifo__data_in[4];
        WData/*99:0*/ top__DOT____Vcellout__L1_RingStop__BRA__1__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1_RingStop__BRA__1__KET____DOT__fifo__data_in[4];
        WData/*99:0*/ top__DOT____Vcellout__L1_RingStop__BRA__2__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1_RingStop__BRA__2__KET____DOT__fifo__data_in[4];
        WData/*99:0*/ top__DOT____Vcellout__L1_RingStop__BRA__3__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1_RingStop__BRA__3__KET____DOT__fifo__data_in[4];
        WData/*99:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__0__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1c_RingStop__BRA__0__KET____DOT__fifo__data_in[4];
        WData/*99:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__1__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1c_RingStop__BRA__1__KET____DOT__fifo__data_in[4];
        WData/*99:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__2__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1c_RingStop__BRA__2__KET____DOT__fifo__data_in[4];
        WData/*99:0*/ top__DOT____Vcellout__L1c_RingStop__BRA__3__KET____DOT__fifo__data_out[4];
        WData/*99:0*/ top__DOT____Vcellinp__L1c_RingStop__BRA__3__KET____DOT__fifo__data_in[4];
        CData/*0:0*/ __Vm_traceActivity[31];
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _combo__TOP__101(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__100(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__102(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__103(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__104(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__105(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__53(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__54(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__55(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__56(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__57(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__58(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__59(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__60(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__62(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__64(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__66(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__68(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__70(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__71(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__72(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__73(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__74(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__75(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__76(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__77(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__83(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__84(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__85(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__86(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__87(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__88(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__89(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__90(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__91(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__92(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__93(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__94(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__95(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__96(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__97(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__98(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__99(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__13(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__14(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__15(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__16(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__17(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__18(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__19(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__20(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__21(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__22(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__23(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__28(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__29(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__30(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__31(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__32(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__33(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__34(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__35(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__36(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__37(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__38(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__39(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__40(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__41(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__42(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__43(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__44(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__45(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__46(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__47(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__48(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__49(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__50(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__51(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__52(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__61(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__63(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__65(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__67(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__69(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__78(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__79(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__80(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__81(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__82(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
