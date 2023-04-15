/**
 * | Port       | name |
 * | ---------- | ---- |
 * | LED2       | P53  |
 */

#ifndef __BSP_LED_H_
#define __BSP_LED_H_

#include "main.h"
#include "STC32G_GPIO_extend.h"

//引脚定义

#define LED2 P53
#define LED2_GPIO GPIO_P5
#define LED2_PIN GPIO_Pin_3


/**
 * @brief  LED灯
 */
typedef enum __STC32_LED_PORT
{
  LED2_PORT,   
} LED_PORT_E;


/**
 * @brief  LED灯的状态
 */
typedef enum __STC32_LED
{
  LED_OFF = 0,       /*!< LED灭  */
  LED_ON = !LED_OFF, /*!< LED亮  */
} LED_STATUS_E;


/**
 * @brief  LED设定状态
 * @param LED_PIN:  按键的引脚 @ref LED1_R_Pin
 * @param LED_STATUS 配置IED状态 @ref LED_STATUS_E
 */
#define SET_LED(LED_PIN, LED_STATUS) (LED_PIN = LED_STATUS)

/**
 * @brief  LED IO初始化
 */
void LED_init();

/**
 * @brief  设定指定LED 亮灭
 * @param LED_PORT @ref LED_PORT_E  LED端口
 * @param led_status @ref LED_PORT_E LED状态
 */
void LED_set(LED_PORT_E LED_PORT, LED_STATUS_E led_status);
/**
 * @brief  获取指定LED状态
 * @param LED_PORT @ref LED_PORT LED端口
 * @return @ref LED_STATUS_E LED的状态
 */
LED_STATUS_E LED_get(LED_PORT_E LED_PORT);

#endif
