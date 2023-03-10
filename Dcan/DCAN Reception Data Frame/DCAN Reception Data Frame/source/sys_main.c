/** @file sys_main.c 
*   @brief Application main file
*   @date 10-MAR-2023
*   @version 1
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "sys_common.h"
#include "can.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */
uint8 data[1000];
uint32 length=0;
uint8 length_byte[4];


int main(void)
{
/* USER CODE BEGIN (3) */


    canInit();
while(1){
    uint32 bytecount =0;
    uint32 i =0;
    uint32 j =0;
    while((canREG1->TXRQx[0] & (1U << ((canMESSAGE_BOX4 - 1U) & 0x1FU))) == 0U);
    canSendRemoteFrame(canREG1, canMESSAGE_BOX3);
    for(j=0;j<10000;j++);
    while(((canREG1->NWDATx[0U] & (1U << ((canMESSAGE_BOX3 - 1U) & 0x1FU)))==0));
    canGetData(canREG1, canMESSAGE_BOX3, &length_byte[i]);
    for(j=0;j<100000;j++);
    length = decode_length();


    for(i=0;i<length;i=bytecount*8){
    canSendRemoteFrame(canREG1, canMESSAGE_BOX1);
    for(j=0;j<10000;j++);
    while(((canREG1->NWDATx[0U] & (1U << ((canMESSAGE_BOX1 - 1U) & 0x1FU)))==0));
    canGetData(canREG1, canMESSAGE_BOX1, &data[i]);

    bytecount++;
    }


    bytecount=0;
    for(i=0;i<length;i=bytecount*8){
    while((canREG1->TXRQx[0] & (1U << ((canMESSAGE_BOX2 - 1U) & 0x1FU))) != 0U);
    canTransmit(canREG1, canMESSAGE_BOX2, &data[i]);
    while((canREG1->TXRQx[0] & (1U << ((canMESSAGE_BOX2 - 1U) & 0x1FU))) == 0U);
    bytecount++;

     }
}

//    for(i=0;i<1000000;i++);
//    for(i=0;i<100000000;i++);
//    canSendRemoteFrame(canREG1, canMESSAGE_BOX1);
//    while(((canREG1->NWDATx[0U] & (1U << ((canMESSAGE_BOX1 - 1U) & 0x1FU)))==0));
//    canGetData(canREG1, canMESSAGE_BOX1, &data[8]);

//    decode_length();
//    for(i=0;i<length;i=bytecount*8){
//    while(((canREG1->NWDATx[0U] & bitIndex)==0));
//    canGetData(canREG1, canMESSAGE_BOX1, &data[i]);
//    bytecount++;
//    }
//    bytecount =0;
//    for(i=0;i<length;i=bytecount*8){
//    canTransmit(canREG1, canMESSAGE_BOX2, &data[i]);


//
//    }
/* USER CODE END */


}


uint32 decode_length(){
    uint8 i;
    uint32 temp;
    uint32 shifter = 8;
    temp = length_byte[0];
    for(i=0;i<3;i++){
        temp = temp + (length_byte[i+1]<< shifter);
        shifter += 8;
    }
    return temp;
}


/* USER CODE BEGIN (4) */
/* USER CODE END */
