/**
 * @file bsp_led.h
 * COPYRIGHT (C) 2022,  chengmeng_2@outlook.com Co., Ltd.
 * All rights reserved.
 * @brief LED
 * @details
 *
 * @version SF ver1.0
 * @version HF PCB.STC32GXXCoreboard-V1.2
 * @date
 * @author cmm
 * @note
 */

#include "bsp_led.h"
#include "STC32G_GPIO_extend.h"
#ifdef __BSP_LED_ENABLED

void LED_init()
{
    GPIO_MODE_OUT_PP(LED2_GPIO, LED2_PIN);
    LED_set(LED2,LED_ON);
}
void LED_DeInit()
{
    MODE_IN_HIZ(LED2_GPIO, LED2_PIN);
}

void LED_set(LED_PORT_E LED_PORT, LED_STATUS_E led_status)
{
    switch (LED_PORT)
    {
        case LED2_PORT:
            LED2 = led_status;
            break;
        default:
            break;
    }

}
LED_STATUS_E LED_get(LED_PORT_E LED_PORT)
{
    LED_STATUS_E led_status = LED_OFF;
   switch (LED_PORT)
    {
        case LED2_PORT:
            led_status = LED2;
            break;
        default:
            break;
    }
    return led_status;
}

#endif /* __BSP_LED_ENABLED */
