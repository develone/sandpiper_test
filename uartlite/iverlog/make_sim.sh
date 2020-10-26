#!/bin/bash
echo "Creating simulation"
iverilog -o uart tb_txuart.v txuart.v
echo "Creating dump.vcd"



