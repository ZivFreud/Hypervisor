#include "major_functions.h"



NTSTATUS MJR_Unsupported(PDEVICE_OBJECT deviceObject, PIRP irp)
{
	PIO_STACK_LOCATION pIoStackIrp = IoGetCurrentIrpStackLocation(irp);
	UNREFERENCED_PARAMETER(deviceObject);
	DbgPrint("Unsupported major function called: %s", GetMjrFunctionName(pIoStackIrp->MajorFunction));
	return STATUS_SUCCESS;
}

NTSTATUS MJR_Create(PDEVICE_OBJECT deviceObject, PIRP irp)
{
	UNREFERENCED_PARAMETER(irp);
	UNREFERENCED_PARAMETER(deviceObject);
	DbgPrint("Driver handler created");
	return STATUS_SUCCESS;
}
NTSTATUS MJR_Close(PDEVICE_OBJECT deviceObject, PIRP irp)
{
	UNREFERENCED_PARAMETER(irp);
	UNREFERENCED_PARAMETER(deviceObject);
	DbgPrint("Driver handler closed");
	return STATUS_SUCCESS;
}
NTSTATUS MJR_IOControl(PDEVICE_OBJECT deviceObject, PIRP irp)
{
	UNREFERENCED_PARAMETER(irp);
	UNREFERENCED_PARAMETER(deviceObject);
	DbgPrint("Driver IO control called");
	return STATUS_SUCCESS;
}
const char* GetMjrFunctionName(UCHAR n)
{
	switch (n)
	{
	case 0:
		return "IRP_MJ_CREATE";
	case 1:
		return "IRP_MJ_CREATE_NAMED_PIPE";
	case 2:
		return "IRP_MJ_CLOSE";
	case 3:
		return "IRP_MJ_READ";
	case 4:
		return "IRP_MJ_WRITE";
	case 5:
		return "IRP_MJ_QUERY_INFORMATION";
	case 6:
		return "IRP_MJ_SET_INFORMATION";
	case 7:
		return "IRP_MJ_QUERY_EA";
	case 8:
		return "IRP_MJ_SET_EA";
	case 9:
		return "IRP_MJ_FLUSH_BUFFERS";
	case 10:
		return "IRP_MJ_QUERY_VOLUME_INFORMATION";
	case 11:
		return "IRP_MJ_SET_VOLUME_INFORMATION";
	case 12:
		return "IRP_MJ_DIRECTORY_CONTROL";
	case 13:
		return "IRP_MJ_FILE_SYSTEM_CONTROL";
	case 14:
		return "IRP_MJ_DEVICE_CONTROL";
	case 15:
		return "IRP_MJ_INTERNAL_DEVICE_CONTROL";
	case 16:
		return "IRP_MJ_SHUTDOWN";
	case 17:
		return "IRP_MJ_LOCK_CONTROL";
	case 18:
		return "IRP_MJ_CLEANUP";
	case 19:
		return "IRP_MJ_CREATE_MAILSLOT";
	case 20:
		return "IRP_MJ_QUERY_SECURITY";
	case 21:
		return "IRP_MJ_SET_SECURITY";
	case 22:
		return "IRP_MJ_POWER";
	case 23:
		return "IRP_MJ_SYSTEM_CONTROL";
	case 24:
		return "IRP_MJ_DEVICE_CHANGE";
	case 25:
		return "IRP_MJ_QUERY_QUOTA";
	case 26:
		return "IRP_MJ_SET_QUOTA";
	case 27:
		return "IRP_MJ_PNP";
	}

	return "NULL";
}
