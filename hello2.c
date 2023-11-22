#include <stdio.h>

//工具代码
typedef struct 
{
    int status;
    void(*statusChange)();
}T_Device;

T_Device g_Device;

void addCallbackFunc(void(*pstatusChange)(int status)){
    g_Device.statusChange = pstatusChange;
}

void run(){
    g_Device.status = 10;
    if (g_Device.status == 10){
        if(g_Device.statusChange != NULL){
            g_Device.statusChange(g_Device.status);
        }
    }
}

//用户代码
void callBack(int status){
    printf("callBack\n");
    printf("status = %d\n",status);
}

void main(){
    addCallbackFunc(callBack);
    run();
}
