/*
* Configuration of module: Rte (Rte_Tester.h)
*
* Created by:              
* Copyright:               
*
* Configured for (MCU):    MPC5567
*
* Module vendor:           ArcCore
* Generator version:       0.0.13
*
* Generated by Arctic Studio (http://arccore.com) 
*/

/* Rte_Tester.h */

#ifndef RTE_TESTER_H
#define RTE_TESTER_H

#include "Rte_Type.h"

#define Rte_Call_Calculator_Multiply Rte_Call_Tester_Calculator_Multiply

UInt8 Rte_IRead_TesterRunnable_Arguments_arg1(void);

UInt8 Rte_IRead_TesterRunnable_Arguments_arg2(void);

void Rte_IWrite_TesterRunnable_Result_result(UInt16 Value);

Std_ReturnType Rte_Call_Tester_Calculator_Multiply(const UInt8 arg1,
		const UInt8 arg2, UInt16* result);

UInt32 Rte_IRead_FreqReqRunnable_FreqReq_freq(void);

void Rte_IWrite_FreqReqRunnable_FreqReqInd_freq(UInt32 Value);

void TesterRunnable(void);

void FreqReqRunnable(void);

#endif
