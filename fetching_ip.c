#include "fetching_ip.h"
#include "fetch.h"
#include "execute.h"

void fetching_ip(
  unsigned int pc[2],
  unsigned int code_mem[CODE_MEM_SIZE/sizeof(int)]){
#pragma HLS INTERFACE s_axilite port=pc
#pragma HLS INTERFACE s_axilite port=code_mem
#pragma HLS INTERFACE ap_ctrl_none port=return
  code_address_t current_pc;
  code_address_t next_pc;
  instruction_t  instruction;
  next_pc = (code_address_t)(pc[0]);
  do{
#pragma HLS PIPELINE off
    current_pc = next_pc;
    fetch(current_pc, code_mem, &instruction);
    execute(current_pc, &next_pc);
  } while (instruction != RET);
  pc[1] = (unsigned int)current_pc;
}
