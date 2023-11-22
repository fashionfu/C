
#include <stdio.h>
#include <stdarg.h>

#include<stddef.h>
#include<setjmp.h>
#include<stdlib.h>

#include "log.h"

typedef struct 
{
    int output;
    int a;
    int b;
    int (*TestEMFunc)(int,int);
}T_EMTest;

T_EMTest *addFunc(int (*TestEMFunc)(int,int),int a,int b,int output){
    T_EMTest *m_EMTest = (T_EMTest *)malloc(sizeof(T_EMTest));
    m_EMTest->a = a;
    m_EMTest->b = b;
    m_EMTest->TestEMFunc = TestEMFunc;
    m_EMTest->output = output;
    return m_EMTest;
}

void runEMTest(T_EMTest *p_EMTest){
    if(p_EMTest != NULL){
        int count = p_EMTest->TestEMFunc(p_EMTest->a,p_EMTest->b);
        if(count == p_EMTest->output){
            printf("success %d\n",count);
        }
        else{
            printf("fail %d ! %d\n",count,p_EMTest->output);
        }
        free(p_EMTest);
    }

}

int add(int a,int b){
    //TODO
    // a = 10 ; //fail 12 ! 3 
    return a+b;
}

// #define OPEN_LOG 1
// //https://blog.csdn.net/Dontla/article/details/122526092 为什么要使用宏函数
// //定义宏之后，编译器直接进行了预编译，这时候调用它，就是直接进行替换
// #define LOG_LEVEL LOG_DEBUG //实现日志等级的打印操作

// typedef enum //枚举类型不小心写成struct了
// {   LOG_DEBUG = 0,
//     LOG_INFO,
//     LOG_WARN,
//     LOG_ERROR,
// }E_LOGLEVEL;

// char *EM_LOGLevelGet(const int level){ // 在这段代码中，EM_LOGLevelGet 函数用于根据给定的日志级别返回对应的日志级别字符串。
//     if(level == LOG_DEBUG){
//         return "DEBUG";
//     }else if(level == LOG_INFO){
//         return "INFO";
//     }else if(level == LOG_WARN){
//         return "WARN";
//     }else if(level == LOG_ERROR){
//         return "ERROR";
//     }
//     return "UNKNOW";
// //const int level 是一个常量整型参数。
// //在函数原型中，const int level 表示函数接受一个名为 level 的整型参数，并且该参数是一个常量，即它的值在函数内部不能被修改。
// //这意味着在函数内部，你不能修改 level 的值。如果尝试修改 level 的值，编译器会报错。
// //这样的参数使用 const 关键字可以提供额外的安全性，防止函数内部意外修改参数的值，从而避免了一些潜在的错误。
// }

// void EM_LOG(const int level,const char *fun,const int line,const char *fmt,...){
//     #ifdef OPEN_LOG
//     va_list arg;
//     va_start(arg,fmt);
//     char buf[1+vsnprintf(NULL,0,fmt,arg)];//https://blog.csdn.net/Rue_lcy/article/details/129689951
//     vsnprintf(buf,sizeof(buf),fmt,arg);
//     va_end(arg);
//     if(level >= LOG_LEVEL){
//         printf("[%s][%s %d] %s \n",EM_LOGLevelGet(level),fun,line,buf);
//     }
//     #endif
// }

// #define em_LOG(level,fmt...) EM_LOG(level,__FUNCTION__,__LINE__,fmt)

// void test_1(char *fmt,...){
//     va_list arg1;
//     va_start(arg1,fmt);
//     #ifdef OPEN_LOG
//     printf("%d \n",va_arg(arg1 ,int));
//     printf("%d \n",va_arg(arg1 ,int));
//     printf("%d \n",va_arg(arg1 ,int));
//     #endif
//     va_end(arg1);
// }
// 这段代码是一个使用可变参数的函数 test_1。可变参数允许函数接受可变数量的参数。
// 在这个函数中，fmt 是一个字符指针类型的参数，用于传递格式化字符串。
// 接下来，使用 va_list 类型的变量 arg1 来存储可变参数的列表。va_list 是一个特殊的类型，用于访问可变参数的值。
// 使用 va_start 宏来初始化 arg1，并将 fmt 作为参数来指定可变参数的开始位置。
// 然后，使用 va_arg 宏来访问可变参数的值。在这个例子中，使用了三次 va_arg，每次都将可变参数的类型和名称作为参数传递给它。
// 最后，使用 va_end 宏来清理可变参数列表。
// 这段代码的作用是打印出传递给 test_1 函数的三个整数参数。

void main(){

    T_EMTest * m_EMTest = addFunc(add,1,2,3);
    runEMTest(m_EMTest);

    int a = 10 ,b = 11;
    // printf ("app start \n");
    // test_1("",a,b,12);
    
    // EM_LOG(LOG_INFO,"app start");
    // EM_LOG(LOG_WARN,"A = %d",a);
    // EM_LOG(LOG_ERROR,"B = %d",b);
    // EM_LOG(LOG_WARN,"APP WARN");
    // EM_LOG(LOG_ERROR,"APP ERROR");

    em_LOG(LOG_INFO,"APP INFO");//可以打印函数和行号，这是最常用的日志打印方式
    em_LOG(LOG_WARN,"APP WARN");//[WARN][main 78] APP WARN
    em_LOG(LOG_WARN,"A = %d",a);//[WARN][main 79] A = 10
    em_LOG(LOG_ERROR,"B = %d",b);//[ERROR][main 80] B = 11
}


// va_list 是一个特殊的类型，用于访问可变参数的值。它是一个特定的类型，
// 由编译器定义，并且与具体的编译器和平台相关。

// va_list 类型通常用于存储可变参数的列表，并提供了一些宏函数，
// 如 va_start、va_arg 和 va_end，用于访问和处理可变参数。

// 在 C 语言中，可变参数函数是一种函数，它接受可变数量的参数。
// 这些参数的类型和数量在编译时是未知的。可变参数函数通常使用 ... 语法来表示可变参数的部分。

// va_list 类型通常是一个指针类型，它指向存储可变参数的内存位置。
// 使用 va_start 宏来初始化 va_list 变量，并将其传递给可变参数的第一个参数。
// 然后，可以使用 va_arg 宏来访问每个可变参数的值。最后，使用 va_end 宏来清理 va_list 变量。
