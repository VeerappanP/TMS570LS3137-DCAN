/** @file sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
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
#include "het.h"
#include "gio.h"

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

int main(void)
{

    uint32_t i;
    hetInit();
    gioSetDirection(hetPORT1, 0xFFFFFFFF);
    while(1){
        gioSetBit(hetPORT1, 0, 1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 0, 0);
        gioSetBit(hetPORT1, 5, 1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 5, 0);
        gioSetBit(hetPORT1, 25, 1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 25, 0);
        gioSetBit(hetPORT1, 18,1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 18,0);
        gioSetBit(hetPORT1, 29, 1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 29, 0);
        gioSetBit(hetPORT1, 27, 1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 27, 0);
        gioSetBit(hetPORT1, 17, 1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 17, 0);
        gioSetBit(hetPORT1, 31, 1);
        for (i=0;i<1000000;i++);
        gioSetBit(hetPORT1, 31, 0);
//
//
//        for (i=0;i<1000000;i++);
//        gioSetBit(hetPORT1, 0, 0);
//        gioSetBit(hetPORT1, 17, 0);
//        gioSetBit(hetPORT1, 31, 0);
//        gioSetBit(hetPORT1, 25, 0);
//        gioSetBit(hetPORT1, 18,0);
//        gioSetBit(hetPORT1, 29, 0);
//        gioSetBit(hetPORT1, 27, 0);
//        gioSetBit(hetPORT1, 5, 0);
//        for (i=0;i<1000000;i++);
    }























/* USER CODE BEGIN (3) */
//    uint32_t i=1000000;
//    hetInit();
//    gioSetDirection(hetPORT1, 0xFFFFFFFF);
//    while(1){
//        gioSetBit(hetPORT1, 0, 1);
//        gioSetBit(hetPORT1, 17, 1);
//        gioSetBit(hetPORT1, 31, 1);
//        gioSetBit(hetPORT1, 25, 1);
//        gioSetBit(hetPORT1, 18,1);
//        gioSetBit(hetPORT1, 29, 1);
//        gioSetBit(hetPORT1, 27, 1);
//        gioSetBit(hetPORT1, 5, 1);
//        for (i=0;i<1000000;i++);
//        gioSetBit(hetPORT1, 0, 0);
//        gioSetBit(hetPORT1, 17, 0);
//        gioSetBit(hetPORT1, 31, 0);
//        gioSetBit(hetPORT1, 25, 0);
//        gioSetBit(hetPORT1, 18,0);
//        gioSetBit(hetPORT1, 29, 0);
//        gioSetBit(hetPORT1, 27, 0);
//        gioSetBit(hetPORT1, 5, 0);
//        for (i=0;i<1000000;i++);
//    }


// while(1){
//     gioSetBit(hetPORT1, 0, 1);
//    uint32_t i=1000000;
//
//    while(i!=0){
//       --i;
//       }
// gioSetBit(hetPORT1, 0, 0);
//
// i=1000000;
// while(i!=0){
//        --i;
//        }
// }
/* USER CODE END */

//    return 0;
}


/* USER CODE BEGIN (4) */
/* USER CODE END */
