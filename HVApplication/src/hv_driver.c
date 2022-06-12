#include "hv_driver.h"

SC_HANDLE HVDriver_OpenService(LPCWSTR driverPath)
{
	SC_HANDLE hSCManager;
	SC_HANDLE hService;

	hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);

	if (hSCManager)
	{
		hService = CreateService(hSCManager, L"HypervisorService",
			L"Hypervisor",
			SERVICE_START | DELETE | SERVICE_STOP,
			SERVICE_KERNEL_DRIVER,
			SERVICE_DEMAND_START,
			SERVICE_ERROR_IGNORE,
			driverPath,
			NULL, NULL, NULL, NULL, NULL);
		if (!hService)
		{
			hService = OpenService(hSCManager, L"HypervisorService",
				SERVICE_START | DELETE | SERVICE_STOP);
		}
		if (hService)
		{
			StartService(hService, 0, NULL);
		}
		else
		{
			LOG_Error("Failed to create/open driver service\n");
			return NULL;
		}
		CloseServiceHandle(hSCManager);
	}
	else
	{
		LOG_Error("Failed to open Service Manager\n");
		return NULL;
	}
	return hService;
}

VOID HVDriver_CloseService(SC_HANDLE hService)
{
	SERVICE_STATUS ss;
	ControlService(hService, SERVICE_CONTROL_STOP, &ss);
	DeleteService(hService);
	CloseServiceHandle(hService);
}