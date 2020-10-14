
SHELL:=/bin/bash

default: show_config go_default

.PHONY: default go_default go_debug go_valgrind lib show_config prep prep_dbg prep_vg compile run

# This must point to the root of the VERILATOR kit
VERILATOR_ROOT := /usr/local/share/verilator
#export VERILATOR_ROOT
# VERILATOR := $(VERILATOR_ROOT)/bin/verilator
VERILATOR := verilator
#SP_REPO := /var/www/SandPiper_dev

# Pick up PERL and other variable settings
include $(VERILATOR_ROOT)/include/verilated.mk

DEBUG_QUIET = --debug --debugi 0 --gdbbt --no-dump-tree
DEBUG_ON = --debug --trace-dups --gdbbt
#DEBUG = $(DEBUG_ON)
VALGRIND_ON = $(DEBUG_ON) --gdb "valgrind -v --leak-check=yes"

##############################################################

SRC_DIR = .
LIB_DIR = $(SP_REPO)/webserver/lib
export LIB_DIR

##############################################################
go_default:   prep     compile run
go_debug:     prep_dbg compile run
go_valgrind:  prep_vg  compile run

lib: $(LIB_DIR)/pseudo_rand.sv

$(LIB_DIR)/pseudo_rand.sv:
	$(SP_REPO)/bin/sandpiper -dev -m4out $(LIB_DIR)/pseudo_rand.m4out.tlv -i $(SP_REPO)/verilog/pseudo_rand.tlv -o $(LIB_DIR)/pseudo_rand.sv

VERILATOR_FLAGS = --cc +librescan +libext+.sv --top-module makerchip -y $(SRC_DIR) -y $(SP_REPO)/verilog -y $(SP_REPO)/verilog/sandhost -y $(SP_REPO)/verilog/proj_default -y $(LIB_DIR) +incdir+$(SRC_DIR) +incdir+$(SRC_DIR)/sv_url_inc +incdir+$(SP_REPO)/verilog +incdir+$(SP_REPO)/verilog/sandhost +incdir+$(SP_REPO)/verilog/proj_default +incdir+$(LIB_DIR) makerchip.sv
VERILATOR_FLAGS += --assert --trace

#show_config: Is the very first time we've executed Verilator after building
#so we make sure to run with --gdbbt, so if it dumps we'll get a trace.
show_config:
	$(VERILATOR) $(DEBUG_QUIET) -V

#prep: Is the very first time we're running a Verilation
#so we make sure to run with --gdbbt, so if it dumps we'll get a trace.
prep:
	$(VERILATOR) $(DEBUG_QUIET) $(VERILATOR_FLAGS)
prep_dbg:
	$(VERILATOR) $(DEBUG_ON)    $(VERILATOR_FLAGS)
prep_vg:
	$(VERILATOR) $(VALGRIND_ON) $(VERILATOR_FLAGS)

compile: lib
	cd obj_dir ; cp $(LIB_DIR)/sim_main.cpp . ; $(MAKE) -j 3 -f $(LIB_DIR)/Makefile_obj

run:
	obj_dir/simx +verilator+error+limit+100

######################################################################

obj_dir:
	mkdir $@

######################################################################

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir *.log *.dmp *.vpd core
