/** @file
*
* MIT License

* Copyright (c) 2017 Leeway213

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*
**/

#pragma once
#include "Driver.h"

typedef struct _INTERRUPT_CONTEXT
{
	WDFDEVICE Device;
	BOOLEAN IsFifoOverrun;
	BOOLEAN IsPacketEnd;
	BOOLEAN IsFifoAvailable;
	BOOLEAN IsIdle;
	UINT8 DataCount;
}INTERRUPT_CONTEXT, *PINTERRUPT_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(INTERRUPT_CONTEXT, InterruptGetContext);

NTSTATUS CirInterruptCreate(_In_ WDFDEVICE Device, _In_ PCM_PARTIAL_RESOURCE_DESCRIPTOR InterruptRaw, _In_ PCM_PARTIAL_RESOURCE_DESCRIPTOR InterruptTrans);

VOID CirInterruptClearState(volatile ULONG * RegBase, UINT32 IntStateRegOffset, ULONG IntState);

EVT_WDF_INTERRUPT_ISR CirEvtInterruptIsr;

EVT_WDF_INTERRUPT_DPC CirEvtInterruptDpc;


