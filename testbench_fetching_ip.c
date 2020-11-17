#include <stdio.h>
#include "fetching_ip.h"

#include "test_basic.h"

int main(){
  unsigned int pc[2];
  pc[0] = 0;
  fetching_ip(pc, code_mem);
  printf("last pc %d\n", pc[1]);
  return 0;
}
