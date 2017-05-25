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
#include "SunxicirInterface.h"

#define CIR_REG_LENGTH 0x54
#define CIR_GPIO_PIN_COUNT 1
#define CIR_DATA_BUFFER_SIZE 64


NTSTATUS CirDeviceCreate(_In_ PWDFDEVICE_INIT DeviceInit);

typedef enum
{
	CIR_MODE_GPIO
}CIR_GPIO_PIN, *PCIR_GPIO_PIN;

typedef struct _DEVICE_CONTEXT
{
	WDFDEVICE FxDevice;

	ULONG SunxicirInterfaceRef;

	volatile ULONG * RegisterBase;

	ULONG RegisterLength;

	WDFINTERRUPT Interrupt;

	BOOL IsReceiving;

	BOOL PulsePrevious;
	
	ULONG DataBuffer[100];
	
	BOOL PulseBuffer[100];

	ULONG DataSize;

	WDFIOTARGET HidInjectorIoTarget;

}DEVICE_CONTEXT, *PDEVICE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, DeviceGetContext);


EVT_WDF_DEVICE_PREPARE_HARDWARE SunxicirEvtDevicePrepareHardware;
EVT_WDF_DEVICE_RELEASE_HARDWARE SunxicirEvtDeviceReleaseHardware;

EVT_WDF_DEVICE_D0_ENTRY SunxicirEvtDeviceD0Entry;
EVT_WDF_DEVICE_D0_EXIT SunxicirEvtDeviceD0Exit;