#ifndef __HVDRIVER_H__
#define __HVDRIVER_H__
#include <Windows.h>
#include "log.h"

/*=================================================
description:
	Create/open a service that loads the driver
params:
	driver_path: the path of the driver (.sys file)
return:
	handle to the service
=================================================*/
SC_HANDLE HVDriver_OpenService(LPCWSTR driverPath);

/*
Close the driver service
*/
VOID HVDriver_CloseService(SC_HANDLE hService);

#endif