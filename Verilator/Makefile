# Generic Makefile for Verilator-based simulation

# ======= USER CONFIGURATION =======
TOP     ?= TopModule       # Set to your top module (without .sv)
TB      ?= tb.cpp          # Set to your testbench source file
VCD     ?= $(TOP).vcd
# ==================================

OBJ_DIR = obj_dir
EXE     = $(OBJ_DIR)/V$(TOP)

all: build run

build:
	verilator --cc $(TOP).sv --exe $(TB) --trace
	make -C $(OBJ_DIR) -f V$(TOP).mk V$(TOP)

run:
	$(EXE)

wave:
	gtkwave $(VCD)

clean:
	rm -rf $(OBJ_DIR) *.vcd *.log
