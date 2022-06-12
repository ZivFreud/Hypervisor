#include <wdm.h>
#include "arch/cpuid.h"
#include "major_functions.h"

DRIVER_UNLOAD DriverUnload;

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
    UNREFERENCED_PARAMETER(pRegistryPath);
	NTSTATUS NtStatus = STATUS_SUCCESS;
    UINT16 uiIndex = 0;
    PDEVICE_OBJECT pDeviceObject = NULL;
    UNICODE_STRING usDriverName, usDosDeviceName;

    DbgPrint("DriverEntry Called \n");

    RtlInitUnicodeString(&usDriverName, L"\\Device\\HypervisorDevice");
    RtlInitUnicodeString(&usDosDeviceName, L"\\DosDevices\\HypervisorDevice");

    NtStatus = IoCreateDevice(pDriverObject, 0,
        &usDriverName,
        FILE_DEVICE_UNKNOWN,
        FILE_DEVICE_SECURE_OPEN,
        FALSE, &pDeviceObject);

    for (uiIndex = 0; uiIndex < IRP_MJ_MAXIMUM_FUNCTION; uiIndex++)
    {
        pDriverObject->MajorFunction[uiIndex] = MJR_Unsupported;
    }

    pDriverObject->MajorFunction[IRP_MJ_CLOSE] = MJR_Close;
    pDriverObject->MajorFunction[IRP_MJ_CREATE] = MJR_Create;
    pDriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = MJR_IOControl;

    pDriverObject->DriverUnload = DriverUnload;

    if (pDeviceObject)
    {
        pDeviceObject->Flags |= DO_BUFFERED_IO;
        pDeviceObject->Flags &= (~DO_DEVICE_INITIALIZING);
    }

    IoCreateSymbolicLink(&usDosDeviceName, &usDriverName);

    return NtStatus;
}

VOID DriverUnload(PDRIVER_OBJECT  DriverObject)
{

    UNICODE_STRING usDosDeviceName;

    DbgPrint("Hypervisor Unload Called \r\n");

    RtlInitUnicodeString(&usDosDeviceName, L"\\DosDevices\\HypervisorDevice");
    IoDeleteSymbolicLink(&usDosDeviceName);

    IoDeleteDevice(DriverObject->DeviceObject);
}