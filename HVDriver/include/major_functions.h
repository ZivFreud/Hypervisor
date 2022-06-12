#ifndef __MAJOR_FUNCTIONS_H__
#define __MAJOR_FUNCTIONS_H__
#include <wdm.h>

NTSTATUS MJR_Unsupported(PDEVICE_OBJECT deviceObject, PIRP irp);

NTSTATUS MJR_Create(PDEVICE_OBJECT deviceObject, PIRP irp);
NTSTATUS MJR_Close(PDEVICE_OBJECT deviceObject, PIRP irp);
NTSTATUS MJR_IOControl(PDEVICE_OBJECT deviceObject, PIRP irp);

const char* GetMjrFunctionName(UCHAR n);

#endif