#ifndef __FETCHING_IP
#define __FETCHING_IP

#include "ap_cint.h"

#define LOG_CODE_MEM_SIZE 12
//size in bytes
#define CODE_MEM_SIZE     (1<<LOG_CODE_MEM_SIZE)

#define RET               0x8067

typedef unsigned int instruction_t;
typedef uint12 code_address_t;

void fetching_ip(
  unsigned int *pc,
  unsigned int *code_mem);

#endif
