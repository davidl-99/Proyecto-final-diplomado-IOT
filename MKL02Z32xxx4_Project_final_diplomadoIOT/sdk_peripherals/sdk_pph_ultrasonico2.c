/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    ultrasonido.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL02Z4.h"
#include "fsl_debug_console.h"
#include "sdk_hal_lptmr0.h"
#include "fsl_clock.h"
#include "sdk_pph_ultrasonico2.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here.
 *

 */ uint32_t time2,distancia2;



/*
 * @brief   Application entry point.
 *
 *
 */
/*void delay(uint32_t delay) {
   uint32_t i;
   for (i = 0; i < delay; i++) {
   __asm volatile ("nop");
   }
   }*/
 /*void waytTime(uint32_t timer) {
 	for (int32_t x=timer; x >=0; --x){
        __asm volatile ("nop");
 	};
 }*/

void waiitTime(uint32_t timer) {
	//uint32_t tiempo = 0x1FFFF;
	/*do {
		tiempo--;
	} while (tiempo != 0x0000);*/

	lptmr0SetTimeValue(0);		//Reset de variable contador de interrupciones

	//espera a que hayan ocurrido por lo menos 100ms interrupciones
	while (lptmr0GetTimeValue() < timer){
	}

    }

int ultra2(void) {


   lptmr0Init();	//inicializa timer0 IRQ cada 10us
//    PRINTF("Hello World\n");

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    time2=0;

			GPIO_PortClear(GPIOB, 1u << 9U);
			waiitTime(30);	//1x1us
			GPIO_PortSet(GPIOB, 1u << 9U);
			waiitTime(100);	//
			GPIO_PortClear(GPIOB, 1u << 9U);

			while (GPIO_ReadPinInput(GPIOB, 13U)==0x00){

			}
			while (GPIO_ReadPinInput(GPIOB, 13U)==0x01){
				time2=time2+2;
				//waytTime();
			}
		    distancia2=time2/58;



    return distancia2 ;
}
