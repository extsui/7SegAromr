/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_userdefine.h
* Version      : CodeGenerator for RL78/G13 V2.05.00.06 [10 Nov 2017]
* Device(s)    : R5F100LE
* Tool-Chain   : CCRL
* Description  : This file includes user definition.
* Creation Date: 
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */
#include <stddef.h>	// NULL
#include "debug.h"	// DPRINTF()

typedef enum {
	TRUE = 1,
	FALSE = 0,
} BOOL;

#define ARRAY_SIZE(x)	(sizeof(x)/sizeof(x[0]))

// クロック周波数(Hz)
// 変更時はこの値を変えること。
// タイマ値計算で使用する。
#define CLOCK_FREQ	(32000000UL)

// 32MHz最速でピンの上げ下げを行うとそれを受ける側の
// INTC割り込みがH/W的に間に合わない問題が発生したので、
// 上げ下げ間に少し遅延を入れる必要がある。
// 以下の定義で約250ns@32MHzの遅延を生成できる。
#define PULSE_DELAY()	do { NOP(); NOP(); NOP(); NOP(); NOP(); } while (0)

#define ASSERT(x)												\
	do {														\
		if (!(x)) {												\
			DPRINTF("Assertion failed: %s, file %s, line %d\n",	\
					#x, __FILE__, __LINE__);					\
			while (1);	/* WDT待ち */							\
		}														\
	} while (0)

/* End user code. Do not edit comment generated here */
#endif
