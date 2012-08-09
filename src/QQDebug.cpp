/**
 * @file   qq_debug.c
 * @author Xiang Wang <xiang_wang@trendmicro.com.cn>
 * @date   Sun May 13 22:13:19 2012
 * 
 * @brief  
 * 
 * 
 */

#include "QQDebug.h"
#include <time.h>
#include <stdio.h>
#include <stdarg.h>

struct tm* get_currenttime()
{
        time_t t;
        time(&t);
        return localtime(&t);
}

void debug_info(const char* format , ...)
{
        char t_str[32] = { 0 };
        char fmt[4096] = { 0 };
        va_list ap;
        struct tm* t = get_currenttime();
        strftime(t_str , sizeof(t_str) , "%T" , t );
        sprintf(fmt , "[\033[32m\033[1m%s\033[0m]  %s\n" , t_str , format);
        va_start(ap, format);
        vfprintf(stdout , fmt , ap);
        va_end(ap);
}
void debug_error(const char* format , ...)
{
        char fmt[4096] = { 0 };
        va_list ap;
        sprintf(fmt , "[\033[31m\033[1mFAIL\033[0m] %s\n" , format);
        va_start(ap, format);
        vfprintf(stderr , fmt , ap);
        va_end(ap);
}
