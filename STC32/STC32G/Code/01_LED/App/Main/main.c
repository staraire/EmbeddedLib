#include "main.h"

void Delay1000ms();

// 下载时，设置ISP软件上频率为24M

/**** 库函数方式 *****/

void main(void)
{
    /** 局部变量定义*/
    /** 变量初始化*/
    WTST = 0; // 设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
    /** 模块初始化*/
    EAXSFR(); // 扩展SFR(XFR)访问使能
    LED_init(); /*!< LED 模块初始化 */
    Tick_init(); // 定时器初始化
    Tick_start(); // 定时器开启
    EA = 1; // 开启总中断
    while (1)
    {
        /* code */
        LED_set(LED2_PORT,LED_ON);
        // Delay1000ms(); // 软件延时
        Tick_Delay(1000); // 定时器延时
        LED_set(LED2_PORT,LED_OFF);
        // Delay1000ms(); // 软件延时
        Tick_Delay(1000); // 定时器延时

    }
    
}

/***** 寄存器方式 *****/

// void main(void)
// {
//     /** 局部变量定义*/
//     /** 变量初始化*/
//     WTST = 0; // 设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
//     /** 模块初始化*/
//     EAXSFR(); // 扩展SFR(XFR)访问使能

//     // LED2 P5.3 

//     // // P5.3设置为双向模式(弱上拉)
//     // // P5M0第四位设置为0 P5M1第四位设置为0
//     // P5M0 &= 0xF7; // 1111 0111 P5M1第四位置0
//     // P5M1 &= 0xF7; // 1111 0111 P5M1第四位置0

//     // P5.3设置为推挽模式(强上拉输出 20mA) 要加限流电阻
//     // P5M0第四位设置为1 P5M1第四位设置为0
//     P5M0 |= 0x08; // 0000 1000 P5M0第四位置1
//     P5M1 &= 0xF7; // 1111 0111 P5M1第四位置0

//     P53 = 1;

//     while (1)
//     {
//         /* code */
//         P53 = 1;
//         Delay1000ms();
//         P53 = 0;
//         Delay1000ms();

//     }
    
// }


void Delay1000ms() //@24.000MHz
{
	unsigned char i, j, k;

	// _nop_();
	// _nop_();
	i = 122;
	j = 193;
	k = 128;
	do
	{
		do
		{
			while (--k)
				;
		} while (--j);
	} while (--i);
}
