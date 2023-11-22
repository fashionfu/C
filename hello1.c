#include <stdio.h>
#include "test.h"
// #include "test.c"//备注第一次：这里的test.c是自己写的，要记得同时include .c文件
//二次更正：当我在cd进入当前C文件夹后，重新把hello1.c文件进行了编译，
//即代码D:\vscode\C> gcc hello1.c test.c -o hello1.exe
//此时，可以完成正常的输出及链接代码块操作，也即上方的第一次更正其实是错误的，并不是正确的代码块链接方式（其实也可以，不算不正确，只是不够准确）
//三次更正：仍然需要include "test.c"
//四次更正：在同时编译hello1.c和test.c文件后，即D:\vscode\C> gcc .\hello1.c .\test.c -o .\hello1
//        此时，不再提示test undefined reference 错误，同时也不需要include "test.c"代码
//        也即说明，是编译的时候需要同时编译？
//上述第四次更正正确：因为有两个文件，需要两个文件都进行编译操作，而非引用代码块 include "test.c"
//重新看了一遍，第二次的时候本来已经同时编译两个文件了，又忘了...//gpt：确保在链接阶段能够找到 test 函数的定义并进行链接

//根本上来说，我直接在hello1.c文件框下直接按F5进行编译时，无法同时编译hello1.c和test.c文件
//因此，必须在终端中输入 D:\vscode\C> gcc .\hello1.c .\test.c -o .\hello1 才能同时进行编译
//在之前的gcc版本问题中，并未解决老版本和新版本gcc重复使用的环境变量问题，也即输入where gcc时，会提供给我两个路径，其中一个C:\G77\bin 包含的是1995年左右的旧版本gcc，需要进行删除操作
//因此，该问题结束，总的来说是终端、编译和版本的综合性问题。

// char a;
// short b;
// int c;

#define LOG_OPEN 1

#define P (3+1)

// #define VERSION_PRE 1
#define VERSION_GOLD 2 

int z;
int sum;

    unsigned char time_buffer[4] = {0x5f,0xcb,0x0f,0x4f};
    unsigned int time;

unsigned int u8Tou32B( unsigned char *buffer ){
    return (((((((unsigned int)buffer[0])<<8)|buffer[1])<<8)|buffer[2])<<8)|buffer[3];
}//十六进制转十进制


// typedef 与 define （替换与别名（宏））
typedef char * PCHAR1;
#define PCHAR2 char *

/*c1、c2都为char *，typedef相当于为char * 引入了一个新的别名 */
PCHAR1 c1,c2;

/*相当于char * c3,c4；c3是char * ，而c4是char       */
PCHAR2 c3,c4;

    // 单片机数据类型
    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;

    uint8 a,b,c;
    unsigned char A,B,C;

// #define NET_CONNECTING 1
// #define NET_CONNECT_SUCCESS 2
// #define NET_CONNECT_FAIL 3
// #define NET_ERROR 4

typedef enum {
        NET_INIT = 0,
        NET_CONNECTING,
        NET_CONNECT_SUCCESS,
        NET_CONNECT_FAIL,
        NET_ERROR,
    }E_NET_STATUS;
//枚举类型可以用于提高代码的可读性和可维护性，因为它可以将一组相关的常量整合到一个类型中，使代码更加清晰。

typedef struct {
    int num;
    int time;
    int money;
}T_Pay;

typedef struct {
    int num;
    int time;
}T_Manager;

typedef struct {
    int system_status;
    int net_status;
    int motor_status[4];
    int pay_status;
    T_Pay m_Pay;
    T_Manager m_Manager;
    //void *(statusCallbackfunc)();  
}T_Device;

T_Device g_Device;
T_Device g_Device_1;

void swap(int data1,int data2){
    int temp = data1;
    data1 = data2;
    data2 = temp;
}

void swap1(int *data1,int *data2){
    int temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

void open(int *key,int num){
    printf("data = %d\n",key[num]);
}

int main(){
    
    printf("hello world!\n");

    // g_Device.net_status = NET_CONNECTING;
    // g_Device.m_Pay.num = 1 ;
    // g_Device_1.net_status = NET_CONNECT_SUCCESS;

    // g_Device.m_Manager.num = 4;

    // printf("manager get the num = %d \n", g_Device.m_Manager.num);

    // printf("Net status = %d \n",g_Device_1.net_status);

#ifdef LOG_OPEN

#ifdef VERSION_PRE
    printf("THIS IS A PRE VERSION\n");
    //TODO
#elif VERSION_GOLD
    printf("THIS IS A GOLD VERSION\n");
    //TODO

    // printf ("sum + %d \n", 10*P);

#endif

    // int ble_status = 0 ;
    // if(ble_status == NET_CONNECTING){
    //     printf("init ing\n");
    // }else if ( ble_status == NET_CONNECT_SUCCESS){
    //     printf("connect ing\n");   
    // }else if ( ble_status == NET_CONNECT_FAIL){
    //     printf("connect success\n");  
    // }
    // else if( ble_status == NET_ERROR){
    //     printf("connect fail\n");  
    // }else{
    //     printf("net init\n");
    // }
 
    // test(); //编译的时候记得同时编译两个.c文件：D:\vscode\C> gcc .\hello1.c .\test.c -o .\hello1
    // test();//               D:\vscode\C> .\hello1
    // test();
    // test();

    // printf("%d %d %d \n",sizeof(a),sizeof(b),sizeof(c));
    
    // time = u8Tou32B(time_buffer);
    // printf("time = %ld s\n",time);

    // scanf("%d",&z);
    // switch(z){
    //         case 1:printf("monday\n");break;
    //         case 2:printf("tuesdat\n");break;
    //         case 3:printf("wednesday\n");break;
    //         case 4:printf("thursday\n");break;
    //         case 5:printf("friday\n");break;
    //     }

    // for (z ; z < 101; z++ ){
    //     sum+= z;
    //     if(sum > 100){
    //         printf("%d\n",sum);
    //     }
    // }

    // E_NET_STATUS net_status;
    // net_status = NET_INIT;
    // if(net_status == NET_INIT){
    //     printf("net init\n");
    // }else if(net_status == NET_CONNECTING){
    //     printf("net connecting\n");
    // }else if(net_status == NET_CONNECT_SUCCESS){
    //     printf("net connect success\n");
    // }else if (net_status == NET_CONNECT_FAIL) {
    //     printf("net connect fail\n");
    // }else {
    //     printf("net error\n");
    // }
    
#endif

// printf ("a 的大小 : %zu\n", sizeof(a));//在C++中，printf 函数期望第一个参数是格式字符串，用于指定输出的格式，
// //然后是根据格式字符串进行格式化的额外参数。格式字符串应该是 const char* 类型。
// printf ("b 的大小 : %zu\n", sizeof(b));

    // int val =10;
    // int *p;// p是一个指针，存储着变量val的地址
    // p = &val;// *p中是变量val的值

    // printf("p = %d *p = %d\n",p,*p); //p = 6422032 *p = 10

    // int a = 10,b = 20;
    // int c = 10,d = 20;
    // swap(a,b);//值未进行交换
    // swap1(&c,&d);
    // printf("a = %d b = %d\n",a,b);
    // printf("c = %d d = %d\n",c,d);

    int key[100]= {0,1,2,3,4,5,6,7,8,9};
    open(key,0);
    open(key,10);//根据代码的逻辑，当调用 open(key, 10) 时，会打印数组 key 中索引为 10 的元素，
    //但是数组的索引是从 0 开始的，所以实际上是访问了数组 key 中不存在的元素，
    //导致打印出的结果是不确定的。

    return 0;
}

