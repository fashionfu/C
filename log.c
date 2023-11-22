
#include "log.h"

char *EM_LOGLevelGet(const int level){
    if(level == LOG_DEBUG){
        return "DEBUG";
    }else if(level == LOG_INFO){
        return "INFO";
    }else if(level == LOG_WARN){
        return "WARN";
    }else if(level == LOG_ERROR){
        return "ERROR";
    }
    return "UNKNOW";
}

void EM_LOG(const int level,const char *fun,const int line,const char *fmt,...){
    #ifdef OPEN_LOG
    va_list arg;
    va_start(arg,fmt);
    char buf[1+vsnprintf(NULL,0,fmt,arg)];//https://blog.csdn.net/Rue_lcy/article/details/129689951
    vsnprintf(buf,sizeof(buf),fmt,arg);
    va_end(arg);
    if(level >= LOG_LEVEL){
        printf("[%s][%s %d] %s \n",EM_LOGLevelGet(level),fun,line,buf);
    }
    #endif
}


