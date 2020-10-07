// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top.tlv:272
    if (vlTOPp->top__DOT__RESP_ld_resp_valid_a3) {
	vlTOPp->top__DOT__rf__DOT__data[(7U & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
					       >> 9U))] 
	    = (((IData)(vlTOPp->top__DOT__EXE_instr_valid_a4) 
		& (~ (IData)(vlTOPp->top__DOT__EXE_valid_mem_instr_a4)))
	        ? (IData)(vlTOPp->top__DOT____Vcellout__alu__f)
	        : (IData)(vlTOPp->top__DOT__RESP_mem_rdata_a3));
    }
    // ALWAYS at top_gen.sv:193
    vlTOPp->top__DOT__L0_Cnt_a0 = vlTOPp->top__DOT__L0_Cnt_n1;
    // ALWAYS at top_gen.sv:293
    vlTOPp->top__DOT__RESP_ld_resp_valid_a4 = vlTOPp->top__DOT__RESP_ld_resp_valid_a3;
    // ALWAYS at top_gen.sv:208
    vlTOPp->top__DOT__EXE_cc_a6 = ((4U & ((IData)(vlTOPp->top__DOT____Vcellout__alu__f) 
					  >> 0xdU)) 
				   | (((0U == (IData)(vlTOPp->top__DOT____Vcellout__alu__f)) 
				       << 1U) | (0U 
						 != 
						 (0x7fffU 
						  & (IData)(vlTOPp->top__DOT____Vcellout__alu__f)))));
    // ALWAYS at top_gen.sv:247
    vlTOPp->top__DOT__EXE_valid_ld_a6 = vlTOPp->top__DOT__EXE_valid_ld_a5;
    // ALWAYS at top_gen.sv:286
    vlTOPp->top__DOT__RESP_LoadPending_a3 = vlTOPp->top__DOT__RESP_LoadPending_a2;
    // ALWAYS at top_gen.sv:256
    vlTOPp->top__DOT__EXE_valid_st_a7 = vlTOPp->top__DOT__EXE_valid_st_a6;
    // ALWAYS at top_gen.sv:240
    vlTOPp->top__DOT__EXE_reg_a_a5 = vlTOPp->top__DOT__rf__DOT__data
	[(7U & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
		>> 6U))];
    // ALWAYS at top_gen.sv:290
    vlTOPp->top__DOT__RESP_StorePending_a3 = vlTOPp->top__DOT__RESP_StorePending_a2;
    // ALWAYS at top_gen.sv:282
    vlTOPp->top__DOT__RESP_FetchPending_a3 = vlTOPp->top__DOT__RESP_FetchPending_a2;
    // ALWAYS at top_gen.sv:243
    vlTOPp->top__DOT__EXE_reg_b_a5 = vlTOPp->top__DOT__rf__DOT__data
	[(7U & (IData)(vlTOPp->top__DOT__EXE_ir_a4))];
    // ALWAYS at top_gen.sv:272
    vlTOPp->top__DOT__FETCH_reset_a2 = vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1;
    // ALWAYS at top_gen.sv:217
    vlTOPp->top__DOT__EXE_instr_valid_a6 = vlTOPp->top__DOT__EXE_instr_valid_a5;
    // ALWAYS at top_gen.sv:299
    vlTOPp->top__DOT__RESP_mem_resp_a3 = vlTOPp->top__DOT__EXE_mem_op_a8;
    // ALWAYS at top_gen.sv:296
    vlTOPp->top__DOT__RESP_mem_rdata_a3 = (0xffffU 
					   & vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U]);
    vlTOPp->passed = (0x64U < (IData)(vlTOPp->top__DOT__L0_Cnt_a0));
    // ALWAYS at top_gen.sv:246
    vlTOPp->top__DOT__EXE_valid_ld_a5 = vlTOPp->top__DOT__EXE_valid_ld_a4;
    // ALWAYS at top_gen.sv:285
    vlTOPp->top__DOT__RESP_LoadPending_a2 = vlTOPp->top__DOT__RESP_LoadPending_a1;
    // ALWAYS at top_gen.sv:255
    vlTOPp->top__DOT__EXE_valid_st_a6 = vlTOPp->top__DOT__EXE_valid_st_a5;
    // ALWAYS at top_gen.sv:289
    vlTOPp->top__DOT__RESP_StorePending_a2 = vlTOPp->top__DOT__RESP_next_store_pending_a2;
    // ALWAYS at top_gen.sv:281
    vlTOPp->top__DOT__RESP_FetchPending_a2 = vlTOPp->top__DOT__RESP_FetchPending_a1;
    // ALWAYS at pseudo_rand_gen.sv:37
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1 
	= vlTOPp->reset;
    // ALWAYS at top_gen.sv:216
    vlTOPp->top__DOT__EXE_instr_valid_a5 = vlTOPp->top__DOT__EXE_instr_valid_a4;
    vlTOPp->top__DOT__RESP_ld_resp_valid_a3 = ((IData)(vlTOPp->top__DOT__RESP_mem_resp_a3) 
					       & (IData)(vlTOPp->top__DOT__RESP_LoadPending_a3));
    // ALWAYS at top_gen.sv:230
    vlTOPp->top__DOT__EXE_mem_op_a8 = vlTOPp->top__DOT__EXE_mem_op_a7;
    // ALWAYS at pseudo_rand_gen.sv:34
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
    // ALWAYS at top_gen.sv:254
    vlTOPp->top__DOT__EXE_valid_st_a5 = vlTOPp->top__DOT__EXE_valid_st_a4;
    // ALWAYS at top_gen.sv:215
    vlTOPp->top__DOT__EXE_instr_valid_a4 = vlTOPp->top__DOT__RESP_fetch_resp_valid_a3;
    // ALWAYS at top_gen.sv:229
    vlTOPp->top__DOT__EXE_mem_op_a7 = ((IData)(vlTOPp->top__DOT__EXE_valid_mem_instr_a6) 
				       | (IData)(vlTOPp->top__DOT__FETCH_instr_valid_a2));
    vlTOPp->top__DOT__RESP_fetch_resp_valid_a3 = ((IData)(vlTOPp->top__DOT__RESP_mem_resp_a3) 
						  & (IData)(vlTOPp->top__DOT__RESP_FetchPending_a3));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x4e4684aU : ((0xfffffffeU & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
					    << 1U)) 
			    ^ (0xc5U & VL_NEGATE_I((IData)(
							   (1U 
							    & vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U]))))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0xc45f864U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
				   >> 0x1fU)) | (0xfffffffeU 
						 & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
						    << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x76874654U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0xf3048b46U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x5cd84848U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x6684e132U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x713d5431U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x7163e168U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0U : (1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
			  >> 0x1fU)));
    // ALWAYS at top_gen.sv:265
    vlTOPp->top__DOT__FETCH_instr_valid_a2 = vlTOPp->top__DOT__FETCH_instr_valid_a1;
    // ALWAYS at top_gen.sv:251
    vlTOPp->top__DOT__EXE_valid_mem_instr_a6 = vlTOPp->top__DOT__EXE_valid_mem_instr_a5;
    vlTOPp->top__DOT__RESP_FetchPending_a1 = (1U & 
					      ((((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) 
						 | (IData)(vlTOPp->top__DOT__EXE_mem_op_a8))
						 ? 0U
						 : 
						((IData)(vlTOPp->top__DOT__FETCH_instr_valid_a2)
						  ? 4U
						  : 
						 ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a6)
						   ? 2U
						   : 
						  ((IData)(vlTOPp->top__DOT__EXE_valid_st_a7)
						    ? 1U
						    : 
						   (((IData)(vlTOPp->top__DOT__RESP_FetchPending_a2) 
						     << 2U) 
						    | (((IData)(vlTOPp->top__DOT__RESP_LoadPending_a2) 
							<< 1U) 
						       | (IData)(vlTOPp->top__DOT__RESP_StorePending_a2))))))) 
					       >> 2U));
    vlTOPp->top__DOT__RESP_LoadPending_a1 = (1U & (
						   (((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) 
						     | (IData)(vlTOPp->top__DOT__EXE_mem_op_a8))
						     ? 0U
						     : 
						    ((IData)(vlTOPp->top__DOT__FETCH_instr_valid_a2)
						      ? 4U
						      : 
						     ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a6)
						       ? 2U
						       : 
						      ((IData)(vlTOPp->top__DOT__EXE_valid_st_a7)
						        ? 1U
						        : 
						       (((IData)(vlTOPp->top__DOT__RESP_FetchPending_a2) 
							 << 2U) 
							| (((IData)(vlTOPp->top__DOT__RESP_LoadPending_a2) 
							    << 1U) 
							   | (IData)(vlTOPp->top__DOT__RESP_StorePending_a2))))))) 
						   >> 1U));
    vlTOPp->top__DOT__RESP_next_store_pending_a2 = 
	(1U & (((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) 
		| (IData)(vlTOPp->top__DOT__EXE_mem_op_a8))
	        ? 0U : ((IData)(vlTOPp->top__DOT__FETCH_instr_valid_a2)
			 ? 4U : ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a6)
				  ? 2U : ((IData)(vlTOPp->top__DOT__EXE_valid_st_a7)
					   ? 1U : (
						   ((IData)(vlTOPp->top__DOT__RESP_FetchPending_a2) 
						    << 2U) 
						   | (((IData)(vlTOPp->top__DOT__RESP_LoadPending_a2) 
						       << 1U) 
						      | (IData)(vlTOPp->top__DOT__RESP_StorePending_a2))))))));
    // ALWAYS at top_gen.sv:250
    vlTOPp->top__DOT__EXE_valid_mem_instr_a5 = vlTOPp->top__DOT__EXE_valid_mem_instr_a4;
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at clk_gate.sv:37
    vlTOPp->top__DOT__clkP_EXE_instr_valid_a6 = ((IData)(vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a6__DOT__latched_clk_en) 
						 & (IData)(vlTOPp->clk));
    // ALWAYS at clk_gate.sv:37
    vlTOPp->top__DOT__clkP_EXE_instr_valid_a5 = ((IData)(vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a5__DOT__latched_clk_en) 
						 & (IData)(vlTOPp->clk));
    vlTOPp->top__DOT__L0_Cnt_n1 = (0xffffU & ((IData)(vlTOPp->reset)
					       ? 0U
					       : ((IData)(1U) 
						  + (IData)(vlTOPp->top__DOT__L0_Cnt_a0))));
    // ALWAYS at clk_gate.sv:35
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
	vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a6__DOT__latched_clk_en 
	    = vlTOPp->top__DOT__EXE_instr_valid_a5;
    }
    // ALWAYS at clk_gate.sv:35
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
	vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a5__DOT__latched_clk_en 
	    = vlTOPp->top__DOT__EXE_instr_valid_a4;
    }
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at clk_gate.sv:37
    vlTOPp->top__DOT__clkP_EXE_instr_valid_a6 = ((IData)(vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a6__DOT__latched_clk_en) 
						 & (IData)(vlTOPp->clk));
    // ALWAYS at clk_gate.sv:37
    vlTOPp->top__DOT__clkP_EXE_instr_valid_a5 = ((IData)(vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a5__DOT__latched_clk_en) 
						 & (IData)(vlTOPp->clk));
    vlTOPp->passed = (0x64U < (IData)(vlTOPp->top__DOT__L0_Cnt_a0));
    vlTOPp->top__DOT__RESP_ld_resp_valid_a3 = ((IData)(vlTOPp->top__DOT__RESP_mem_resp_a3) 
					       & (IData)(vlTOPp->top__DOT__RESP_LoadPending_a3));
    vlTOPp->top__DOT__L0_Cnt_n1 = (0xffffU & ((IData)(vlTOPp->reset)
					       ? 0U
					       : ((IData)(1U) 
						  + (IData)(vlTOPp->top__DOT__L0_Cnt_a0))));
    vlTOPp->top__DOT__EXE_valid_br_taken_a6 = (((IData)(vlTOPp->top__DOT__EXE_instr_valid_a6) 
						& (IData)(vlTOPp->top__DOT__EXE_br_a6)) 
					       & ((IData)(vlTOPp->top__DOT__EXE_cc_a6) 
						  == (IData)(vlTOPp->top__DOT__EXE_dest_a6)));
    // ALWAYS at clk_gate.sv:35
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
	vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a6__DOT__latched_clk_en 
	    = vlTOPp->top__DOT__EXE_instr_valid_a5;
    }
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[0U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x4e4684aU : ((0xfffffffeU & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
					    << 1U)) 
			    ^ (0xc5U & VL_NEGATE_I((IData)(
							   (1U 
							    & vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[8U]))))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[1U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0xc45f864U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[0U] 
				   >> 0x1fU)) | (0xfffffffeU 
						 & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
						    << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[2U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x76874654U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[1U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[3U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0xf3048b46U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[2U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[4U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x5cd84848U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[3U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[5U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x6684e132U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[4U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[6U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x713d5431U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[5U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[7U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0x7163e168U : ((1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[6U] 
				    >> 0x1fU)) | (0xfffffffeU 
						  & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
						     << 1U))));
    vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1[8U] 
	= ((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1)
	    ? 0U : (1U & (vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2[7U] 
			  >> 0x1fU)));
    vlTOPp->top__DOT__RESP_fetch_resp_valid_a3 = ((IData)(vlTOPp->top__DOT__RESP_mem_resp_a3) 
						  & (IData)(vlTOPp->top__DOT__RESP_FetchPending_a3));
    // ALWAYS at clk_gate.sv:35
    if ((1U & (~ (IData)(vlTOPp->clk)))) {
	vlTOPp->top__DOT__gen_clkP_EXE_instr_valid_a5__DOT__latched_clk_en 
	    = vlTOPp->top__DOT__EXE_instr_valid_a4;
    }
    vlTOPp->top__DOT__EXE_valid_ld_a4 = ((IData)(vlTOPp->top__DOT__EXE_instr_valid_a4) 
					 & (6U == (0xfU 
						   & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
						      >> 0xcU))));
    vlTOPp->top__DOT__EXE_valid_st_a4 = ((IData)(vlTOPp->top__DOT__EXE_instr_valid_a4) 
					 & (7U == (0xfU 
						   & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
						      >> 0xcU))));
    vlTOPp->top__DOT__RESP_FetchPending_a1 = (1U & 
					      ((((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) 
						 | (IData)(vlTOPp->top__DOT__EXE_mem_op_a8))
						 ? 0U
						 : 
						((IData)(vlTOPp->top__DOT__FETCH_instr_valid_a2)
						  ? 4U
						  : 
						 ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a6)
						   ? 2U
						   : 
						  ((IData)(vlTOPp->top__DOT__EXE_valid_st_a7)
						    ? 1U
						    : 
						   (((IData)(vlTOPp->top__DOT__RESP_FetchPending_a2) 
						     << 2U) 
						    | (((IData)(vlTOPp->top__DOT__RESP_LoadPending_a2) 
							<< 1U) 
						       | (IData)(vlTOPp->top__DOT__RESP_StorePending_a2))))))) 
					       >> 2U));
    vlTOPp->top__DOT__RESP_LoadPending_a1 = (1U & (
						   (((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) 
						     | (IData)(vlTOPp->top__DOT__EXE_mem_op_a8))
						     ? 0U
						     : 
						    ((IData)(vlTOPp->top__DOT__FETCH_instr_valid_a2)
						      ? 4U
						      : 
						     ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a6)
						       ? 2U
						       : 
						      ((IData)(vlTOPp->top__DOT__EXE_valid_st_a7)
						        ? 1U
						        : 
						       (((IData)(vlTOPp->top__DOT__RESP_FetchPending_a2) 
							 << 2U) 
							| (((IData)(vlTOPp->top__DOT__RESP_LoadPending_a2) 
							    << 1U) 
							   | (IData)(vlTOPp->top__DOT__RESP_StorePending_a2))))))) 
						   >> 1U));
    vlTOPp->top__DOT__RESP_next_store_pending_a2 = 
	(1U & (((IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1) 
		| (IData)(vlTOPp->top__DOT__EXE_mem_op_a8))
	        ? 0U : ((IData)(vlTOPp->top__DOT__FETCH_instr_valid_a2)
			 ? 4U : ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a6)
				  ? 2U : ((IData)(vlTOPp->top__DOT__EXE_valid_st_a7)
					   ? 1U : (
						   ((IData)(vlTOPp->top__DOT__RESP_FetchPending_a2) 
						    << 2U) 
						   | (((IData)(vlTOPp->top__DOT__RESP_LoadPending_a2) 
						       << 1U) 
						      | (IData)(vlTOPp->top__DOT__RESP_StorePending_a2))))))));
    vlTOPp->top__DOT____Vcellinp__alu__b = ((IData)(vlTOPp->top__DOT__EXE_valid_mem_instr_a5)
					     ? ((0xffc0U 
						 & (VL_NEGATE_I((IData)(
									(1U 
									 & ((IData)(vlTOPp->top__DOT__EXE_offset6_a5) 
									    >> 5U)))) 
						    << 6U)) 
						| (IData)(vlTOPp->top__DOT__EXE_offset6_a5))
					     : (IData)(vlTOPp->top__DOT__EXE_reg_b_a5));
    vlTOPp->top__DOT__FETCH_instr_valid_a1 = (((((IData)(vlTOPp->top__DOT__FETCH_reset_a2) 
						 & (~ (IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1))) 
						| ((IData)(vlTOPp->top__DOT__RESP_mem_resp_a3) 
						   & (IData)(vlTOPp->top__DOT__RESP_StorePending_a3))) 
					       | (IData)(vlTOPp->top__DOT__RESP_ld_resp_valid_a4)) 
					      | ((IData)(vlTOPp->top__DOT__EXE_instr_valid_a6) 
						 & (~ 
						    ((IData)(vlTOPp->top__DOT__EXE_valid_mem_instr_a6) 
						     | (IData)(vlTOPp->top__DOT__EXE_valid_br_taken_a6)))));
    vlTOPp->top__DOT__EXE_ir_a3 = ((IData)(vlTOPp->top__DOT__RESP_fetch_resp_valid_a3)
				    ? (IData)(vlTOPp->top__DOT__RESP_mem_rdata_a3)
				    : (IData)(vlTOPp->top__DOT__EXE_ir_a4));
    vlTOPp->top__DOT__EXE_valid_mem_instr_a4 = ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a4) 
						| (IData)(vlTOPp->top__DOT__EXE_valid_st_a4));
    // ALWAYS at top.tlv:236
    if ((0U == (IData)(vlTOPp->top__DOT__EXE_aluop_a5))) {
	vlTOPp->top__DOT____Vcellout__alu__f = (0xffffU 
						& ((IData)(vlTOPp->top__DOT__EXE_reg_a_a5) 
						   + (IData)(vlTOPp->top__DOT____Vcellinp__alu__b)));
    } else {
	if ((1U == (IData)(vlTOPp->top__DOT__EXE_aluop_a5))) {
	    vlTOPp->top__DOT____Vcellout__alu__f = 
		((IData)(vlTOPp->top__DOT__EXE_reg_a_a5) 
		 & (IData)(vlTOPp->top__DOT____Vcellinp__alu__b));
	} else {
	    if ((2U == (IData)(vlTOPp->top__DOT__EXE_aluop_a5))) {
		vlTOPp->top__DOT____Vcellout__alu__f 
		    = (0xffffU & (~ (IData)(vlTOPp->top__DOT__EXE_reg_a_a5)));
	    }
	}
    }
}

void Vtop::_initial__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at top.tlv:264
    vlTOPp->top__DOT__rf__DOT__data[0U] = 0U;
    vlTOPp->top__DOT__rf__DOT__data[1U] = 0U;
    vlTOPp->top__DOT__rf__DOT__data[2U] = 0U;
    vlTOPp->top__DOT__rf__DOT__data[3U] = 0U;
    vlTOPp->top__DOT__rf__DOT__data[4U] = 0U;
    vlTOPp->top__DOT__rf__DOT__data[5U] = 0U;
    vlTOPp->top__DOT__rf__DOT__data[6U] = 0U;
    vlTOPp->top__DOT__rf__DOT__data[7U] = 0U;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top_gen.sv:212
    vlTOPp->top__DOT__EXE_dest_a6 = vlTOPp->top__DOT__EXE_dest_a5;
    // ALWAYS at top_gen.sv:205
    vlTOPp->top__DOT__EXE_br_a6 = vlTOPp->top__DOT__EXE_br_a5;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top_gen.sv:211
    vlTOPp->top__DOT__EXE_dest_a5 = (7U & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
					   >> 9U));
    // ALWAYS at top_gen.sv:204
    vlTOPp->top__DOT__EXE_br_a5 = (0U == (0xfU & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
						  >> 0xcU)));
    // ALWAYS at top_gen.sv:201
    vlTOPp->top__DOT__EXE_aluop_a5 = ((1U == (0xfU 
					      & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
						 >> 0xcU)))
				       ? 0U : ((5U 
						== 
						(0xfU 
						 & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
						    >> 0xcU)))
					        ? 1U
					        : (
						   (9U 
						    == 
						    (0xfU 
						     & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
							>> 0xcU)))
						    ? 2U
						    : 0U)));
    // ALWAYS at top_gen.sv:233
    vlTOPp->top__DOT__EXE_offset6_a5 = (0x3fU & (IData)(vlTOPp->top__DOT__EXE_ir_a4));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__EXE_valid_br_taken_a6 = (((IData)(vlTOPp->top__DOT__EXE_instr_valid_a6) 
						& (IData)(vlTOPp->top__DOT__EXE_br_a6)) 
					       & ((IData)(vlTOPp->top__DOT__EXE_cc_a6) 
						  == (IData)(vlTOPp->top__DOT__EXE_dest_a6)));
    vlTOPp->top__DOT__FETCH_instr_valid_a1 = (((((IData)(vlTOPp->top__DOT__FETCH_reset_a2) 
						 & (~ (IData)(vlTOPp->top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1))) 
						| ((IData)(vlTOPp->top__DOT__RESP_mem_resp_a3) 
						   & (IData)(vlTOPp->top__DOT__RESP_StorePending_a3))) 
					       | (IData)(vlTOPp->top__DOT__RESP_ld_resp_valid_a4)) 
					      | ((IData)(vlTOPp->top__DOT__EXE_instr_valid_a6) 
						 & (~ 
						    ((IData)(vlTOPp->top__DOT__EXE_valid_mem_instr_a6) 
						     | (IData)(vlTOPp->top__DOT__EXE_valid_br_taken_a6)))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top_gen.sv:220
    vlTOPp->top__DOT__EXE_ir_a4 = vlTOPp->top__DOT__EXE_ir_a3;
    vlTOPp->top__DOT__EXE_ir_a3 = ((IData)(vlTOPp->top__DOT__RESP_fetch_resp_valid_a3)
				    ? (IData)(vlTOPp->top__DOT__RESP_mem_rdata_a3)
				    : (IData)(vlTOPp->top__DOT__EXE_ir_a4));
    vlTOPp->top__DOT__EXE_valid_ld_a4 = ((IData)(vlTOPp->top__DOT__EXE_instr_valid_a4) 
					 & (6U == (0xfU 
						   & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
						      >> 0xcU))));
    vlTOPp->top__DOT__EXE_valid_st_a4 = ((IData)(vlTOPp->top__DOT__EXE_instr_valid_a4) 
					 & (7U == (0xfU 
						   & ((IData)(vlTOPp->top__DOT__EXE_ir_a4) 
						      >> 0xcU))));
    vlTOPp->top__DOT__EXE_valid_mem_instr_a4 = ((IData)(vlTOPp->top__DOT__EXE_valid_ld_a4) 
						| (IData)(vlTOPp->top__DOT__EXE_valid_st_a4));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__9\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT____Vcellinp__alu__b = ((IData)(vlTOPp->top__DOT__EXE_valid_mem_instr_a5)
					     ? ((0xffc0U 
						 & (VL_NEGATE_I((IData)(
									(1U 
									 & ((IData)(vlTOPp->top__DOT__EXE_offset6_a5) 
									    >> 5U)))) 
						    << 6U)) 
						| (IData)(vlTOPp->top__DOT__EXE_offset6_a5))
					     : (IData)(vlTOPp->top__DOT__EXE_reg_b_a5));
    // ALWAYS at top.tlv:236
    if ((0U == (IData)(vlTOPp->top__DOT__EXE_aluop_a5))) {
	vlTOPp->top__DOT____Vcellout__alu__f = (0xffffU 
						& ((IData)(vlTOPp->top__DOT__EXE_reg_a_a5) 
						   + (IData)(vlTOPp->top__DOT____Vcellinp__alu__b)));
    } else {
	if ((1U == (IData)(vlTOPp->top__DOT__EXE_aluop_a5))) {
	    vlTOPp->top__DOT____Vcellout__alu__f = 
		((IData)(vlTOPp->top__DOT__EXE_reg_a_a5) 
		 & (IData)(vlTOPp->top__DOT____Vcellinp__alu__b));
	} else {
	    if ((2U == (IData)(vlTOPp->top__DOT__EXE_aluop_a5))) {
		vlTOPp->top__DOT____Vcellout__alu__f 
		    = (0xffffU & (~ (IData)(vlTOPp->top__DOT__EXE_reg_a_a5)));
	    }
	}
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->top__DOT__clkP_EXE_instr_valid_a6) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a6)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__clkP_EXE_instr_valid_a5) 
	 & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a5)))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->top__DOT__clkP_EXE_instr_valid_a6) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a6))))) {
	vlTOPp->_multiclk__TOP__7(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->top__DOT__clkP_EXE_instr_valid_a5) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a5))))) {
	vlTOPp->_multiclk__TOP__9(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a6 
	= vlTOPp->top__DOT__clkP_EXE_instr_valid_a6;
    vlTOPp->__Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a5 
	= vlTOPp->top__DOT__clkP_EXE_instr_valid_a5;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__4(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    cyc_cnt = VL_RAND_RESET_I(32);
    passed = VL_RAND_RESET_I(1);
    failed = VL_RAND_RESET_I(1);
    top__DOT__L0_Cnt_n1 = VL_RAND_RESET_I(16);
    top__DOT__L0_Cnt_a0 = VL_RAND_RESET_I(16);
    top__DOT__EXE_aluop_a5 = VL_RAND_RESET_I(4);
    top__DOT__EXE_br_a5 = VL_RAND_RESET_I(1);
    top__DOT__EXE_br_a6 = VL_RAND_RESET_I(1);
    top__DOT__EXE_cc_a6 = VL_RAND_RESET_I(3);
    top__DOT__EXE_dest_a5 = VL_RAND_RESET_I(3);
    top__DOT__EXE_dest_a6 = VL_RAND_RESET_I(3);
    top__DOT__EXE_instr_valid_a4 = VL_RAND_RESET_I(1);
    top__DOT__EXE_instr_valid_a5 = VL_RAND_RESET_I(1);
    top__DOT__EXE_instr_valid_a6 = VL_RAND_RESET_I(1);
    top__DOT__EXE_ir_a3 = VL_RAND_RESET_I(16);
    top__DOT__EXE_ir_a4 = VL_RAND_RESET_I(16);
    top__DOT__EXE_mem_op_a7 = VL_RAND_RESET_I(1);
    top__DOT__EXE_mem_op_a8 = VL_RAND_RESET_I(1);
    top__DOT__EXE_offset6_a5 = VL_RAND_RESET_I(6);
    top__DOT__EXE_reg_a_a5 = VL_RAND_RESET_I(16);
    top__DOT__EXE_reg_b_a5 = VL_RAND_RESET_I(16);
    top__DOT__EXE_valid_br_taken_a6 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_ld_a4 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_ld_a5 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_ld_a6 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_mem_instr_a4 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_mem_instr_a5 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_mem_instr_a6 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_st_a4 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_st_a5 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_st_a6 = VL_RAND_RESET_I(1);
    top__DOT__EXE_valid_st_a7 = VL_RAND_RESET_I(1);
    top__DOT__FETCH_instr_valid_a1 = VL_RAND_RESET_I(1);
    top__DOT__FETCH_instr_valid_a2 = VL_RAND_RESET_I(1);
    top__DOT__FETCH_reset_a2 = VL_RAND_RESET_I(1);
    top__DOT__RESP_FetchPending_a1 = VL_RAND_RESET_I(1);
    top__DOT__RESP_FetchPending_a2 = VL_RAND_RESET_I(1);
    top__DOT__RESP_FetchPending_a3 = VL_RAND_RESET_I(1);
    top__DOT__RESP_LoadPending_a1 = VL_RAND_RESET_I(1);
    top__DOT__RESP_LoadPending_a2 = VL_RAND_RESET_I(1);
    top__DOT__RESP_LoadPending_a3 = VL_RAND_RESET_I(1);
    top__DOT__RESP_StorePending_a2 = VL_RAND_RESET_I(1);
    top__DOT__RESP_StorePending_a3 = VL_RAND_RESET_I(1);
    top__DOT__RESP_fetch_resp_valid_a3 = VL_RAND_RESET_I(1);
    top__DOT__RESP_ld_resp_valid_a3 = VL_RAND_RESET_I(1);
    top__DOT__RESP_ld_resp_valid_a4 = VL_RAND_RESET_I(1);
    top__DOT__RESP_mem_rdata_a3 = VL_RAND_RESET_I(16);
    top__DOT__RESP_mem_resp_a3 = VL_RAND_RESET_I(1);
    top__DOT__RESP_next_store_pending_a2 = VL_RAND_RESET_I(1);
    top__DOT__clkP_EXE_instr_valid_a5 = VL_RAND_RESET_I(1);
    top__DOT__clkP_EXE_instr_valid_a6 = VL_RAND_RESET_I(1);
    top__DOT____Vcellout__alu__f = VL_RAND_RESET_I(16);
    top__DOT____Vcellinp__alu__b = VL_RAND_RESET_I(16);
    VL_RAND_RESET_W(257,top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a1);
    VL_RAND_RESET_W(257,top__DOT__pseudo_rand__DOT__DEFAULT_lfsr_a2);
    top__DOT__pseudo_rand__DOT__DEFAULT_reset_a1 = VL_RAND_RESET_I(1);
    top__DOT__gen_clkP_EXE_instr_valid_a5__DOT__latched_clk_en = VL_RAND_RESET_I(1);
    top__DOT__gen_clkP_EXE_instr_valid_a6__DOT__latched_clk_en = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
	    top__DOT__rf__DOT__data[__Vi0] = VL_RAND_RESET_I(16);
    }}
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a6 = VL_RAND_RESET_I(1);
    __Vclklast__TOP__top__DOT__clkP_EXE_instr_valid_a5 = VL_RAND_RESET_I(1);
}
