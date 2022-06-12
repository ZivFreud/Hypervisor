#include <Windows.h>

#include "hv_driver.h"
#include "application.h"
#include "log.h"

int main()
{
	int argc = 0;
	LPWSTR* pArgvW = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (argc < 2)
	{
		LOG_Error("Please enter the path of the hypervisor driver (the .sys file)\n");
		return 0;
	}

	LPCWSTR driver_path = pArgvW[1];

	LOG_Info("Opening service\n");
	SC_HANDLE hService = HVDriver_OpenService(driver_path);

	LOG_Info("Press Enter to continue");
	getchar();

	HANDLE hFile;
	hFile = CreateFile(L"\\\\.\\HypervisorDevice",
		GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, 0, NULL);

	if (hFile != INVALID_HANDLE_VALUE)
	{
		LOG_Info("Successfully opend a handle to the driver\n");
		AppRun(hFile);
		CloseHandle(hFile);
	}
	else 
	{
		LOG_Error("Failed to open driver handle\n");
	}

	LOG_Info("Closing service\n");
	HVDriver_CloseService(hService);

	LocalFree(pArgvW);
	return 0;
}