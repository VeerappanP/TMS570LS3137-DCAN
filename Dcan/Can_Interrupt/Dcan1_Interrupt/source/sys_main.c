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
#include "sys_core.h"
#include "sci.h"

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
uint32 rx_length =0;
uint32 i =0;
uint8   data[100U];
uint8   data1[100U];
//uint8	data[8U] = 	{0x62U, 0x3FU, 0x09U, 0x32U, 0xA9U, 0xFEU, 0x76U, 0x9EU};
uint8   tx_done=0;
uint32 byte = 0;
uint32 byte_count =0;
uint32 length=0;

int main(void)
{
/* USER CODE BEGIN (3) */
    _enable_interrupt_();
    sciInit();
    canInit();

/* USER CODE END */

    while(1);
}


void sciNotification(sciBASE_t *sci, uint32 flags)
{
/*  enter user code between the USER CODE BEGIN and USER CODE END. */
/* USER CODE BEGIN (29) */
    if(flags==11){
    uint32 k;
    data[i] = (uint8) (sci->RD & 0x000000FFU);
    rx_length++;
    i++;
    if (data[i - 1] == 0x0DU)
    {
        uint32 j;
        byte = 0;
        for (j = 0; j < rx_length; j=byte*8)
        {
//            tx_done=0;
            canTransmit(canREG1, canMESSAGE_BOX1, &data[j]);
//            while(tx_done==0);
            for(k=0;k<10000;k++);
            byte++;
        }
        i = 0;
        rx_length = 0;
        byte =0;
       }
    }

/* USER CODE END */
}



void canMessageNotification(canBASE_t *node,uint32 messageBox)
{
/*  enter user code between the USER CODE BEGIN and USER CODE END. */
/* USER CODE BEGIN (15) */
    if(messageBox == canMESSAGE_BOX1){
        tx_done=1;
    }
    if(messageBox == canMESSAGE_BOX2){
                uint32 i;
                while(!canIsRxMessageArrived(node, canMESSAGE_BOX2));
                canGetData(node, canMESSAGE_BOX2, &data1[byte_count]);
                for(i=byte_count;i<(byte_count+8);i++){
                            if(data[i]==0x0DU){
                                utran();
                                break;
                            }
                          length++;
                        }
                byte_count+=8;


       }

/* USER CODE END */
}
void utran(){
    uint32 l;
    uint32 k;

    for(l=0;l<length;l++){
        sciREG->TD=data1[l];
        for(k=0;k<100000;k++);
    }
    byte = 0;
    length =0;
    byte_count =4294967288;
    rx_length =0;
    i=0;

}
//void length_byte_splitter( uint32 length1){
//
//    uint32 i;
//    uint32 as = 0xFF;
//    uint8 shift = 0;
//    for(i=0;i<4;i++){
//        length_byte[i] = (length1 & as)>>shift;
//        shift += 8;
//        as = as << 8;
//     }
//}
/* USER CODE BEGIN (4) */
/* USER CODE END */
