#include "log.h"

void LOG_Error(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf("[!] ");
    vprintf(fmt, args);
    va_end(args);
}
void LOG_Warning(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf("[?] ");
    vprintf(fmt, args);
    va_end(args);
}
void LOG_Info(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    printf("[*] ");
    vprintf(fmt, args);
    va_end(args);
}