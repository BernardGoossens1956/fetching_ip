/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xfetching_ip_hw.h"

unsigned int *pc  =
  (unsigned int *)
  (XPAR_XFETCHING_IP_0_S_AXI_CONTROL_BASEADDR
 +      XFETCHING_IP_CONTROL_ADDR_PC_BASE);
unsigned int *mem =
  (unsigned int *)
  (XPAR_XFETCHING_IP_0_S_AXI_CONTROL_BASEADDR
 +      XFETCHING_IP_CONTROL_ADDR_CODE_MEM_BASE);

unsigned int code_memory[16]=
{
   0xff010113,
   0x00112623,
   0x00812423,
   0x00c0006f,
   0x00000593,
   0x00000613,
   0x00000013,
   0x00000693,
   0x00c59463,
   0x00000713,
   0x00c12083,
   0x00812403,
   0x01010113,
   0x00008067
};

int main()
{
  unsigned int i;
  pc[0] = 0;
  pc[1] = 0;
  for (i=0; i<16; i++)
    mem[i] = code_memory[i];

  init_platform();

  while (pc[1]==0);
  print("pc ");
  xil_printf("%d", pc[1]);
  print("\n\r");

  cleanup_platform();
  return 0;
}
