#ifndef __MAIN_H_
#define __MAIN_H_
#ifdef __cplusplus
extern "C"
{
#endif
#include "config.h"

// 硬件开源地址：https://oshwhub.com/wei-lai-dian-zi-gong-zuo-shi/zui-xiao-xi-tong-stc32g12k128
// PCB图：https://image-pro.lceda.cn/pullimages/c931ad8cb5b349a3918025d5759fd197.webp
#define HF_VERSION ("STC32G12K128-340")
#define SF_VERSION ("C251_V1.0.0_20220905")

// #define __BSP_LED_ENABLED
// #define __BSP_KEY_ENABLED
// #define DBG_ENABLE
// #define DBG_NOLINE
// #define DBG_COLOR
// #define RT_NOASSERT
#include "rtdbg.h"
#include "bsp_SysTick.h"
#define __BSP_LED_ENABLED
#ifdef __BSP_LED_ENABLED
#include "bsp_led.h"
#endif
#ifdef __BSP_KEY_ENABLED
#include "bsp_key.h"
#endif
#ifdef __cplusplus
}
#endif
#endif
