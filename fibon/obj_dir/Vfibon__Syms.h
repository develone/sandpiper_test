// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vfibon__Syms_H_
#define _Vfibon__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vfibon.h"

// SYMS CLASS
class Vfibon__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vfibon*                        TOPp;
    
    // CREATORS
    Vfibon__Syms(Vfibon* topp, const char* namep);
    ~Vfibon__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
