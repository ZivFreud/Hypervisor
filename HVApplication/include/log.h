#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>
#include <stdarg.h>


void LOG_Error(const char* fmt, ...);
void LOG_Warning(const char* fmt, ...);
void LOG_Info(const char* fmt, ...);

#endif