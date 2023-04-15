#include "bsp_SysTick.h"
#include "main.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint32_t l_systemTick; /*!<系统滴答时钟计数 */
/* Private function prototypes -----------------------------------------------*/
void Timer0Init(void); // 1毫秒@24.000MHz
/* Private functions ---------------------------------------------------------*/

void Tick_init(void)
{
    Timer0Init();
    ET0 = 1; // 开定时器0中断
}

void Tick_start(void)
{
    TR0 = 1; // 定时器0开始计时
}

void Tick_stop(void)
{
    TR0 = 0; // 定时器0开始计时
}

void Tick_reset(void)
{
    l_systemTick = 0;
}
uint32_t Tick_GetClock()
{
    return l_systemTick;
}

void Tick_Delay(uint32_t ms)
{
    uint32_t tick_last = l_systemTick;
    while (l_systemTick < ( ms+tick_last))
    {
    }
}

void Timer0Init(void) // 1毫秒@24.000MHz
{
    AUXR |= 0x80; // 定时器时钟1T模式
    TMOD &= 0xF0; // 设置定时器模式
    TL0 = 0x40;   // 设置定时初始值
    TH0 = 0xA2;   // 设置定时初始值
    TF0 = 0;      // 清除TF0标志
}

void Timer0_isr(void) interrupt 1
{
    l_systemTick++;
}
