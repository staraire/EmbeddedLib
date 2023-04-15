#include "main.h"

void main(void)
{
    WTST = 0; // 设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
    EAXSFR(); // 扩展SFR(XFR)访问使能
    while (1)
    {
        /* code */
    }
    
}