
#ifndef _EM_LOG_H_
#define _EM_LOG_H_

#include <stdio.h>
#include <stdarg.h>

#define OPEN_LOG 1
#define LOG_LEVEL LOG_DEBUG //实现日志等级的打印操作

typedef enum //枚举类型不小心写成struct了
{   LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
}E_LOGLEVEL;

void EM_LOG(const int level,const char *fun,const int line,const char *fmt,...);//这里不要忘记了;号

#define em_LOG(level,fmt...) EM_LOG(level,__FUNCTION__,__LINE__,fmt)

#endif