#include <stdio.h>
#include "test.h"


static void test_printf(){
    printf("test_printf\n");
}

void test(){
    static int time = 0;//只会在首次进行初始化时，time = 0；后续再调用函数时，不会再重置为0
    //但如果没有static关键字，time每次都会初始化，也即无论怎么调用都没有生命周期了
    time ++;
    printf("time = %d\n",time);
    // test_printf();
}

