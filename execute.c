#include "fetching_ip.h"

code_address_t compute_next_pc(
  code_address_t pc){
#pragma HLS INLINE off
  code_address_t next_pc;
  next_pc = pc + 4;
  return next_pc;
}
void execute(
  code_address_t current_pc,
  code_address_t *next_pc){
#pragma HLS INLINE off
  *next_pc = compute_next_pc(current_pc);
}
