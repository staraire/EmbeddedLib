#ifndef __MAIN_H_
#define __MAIN_H_
#ifdef __cplusplus
extern "C"
{
#endif
#include "config.h"
#define HF_VERSION ("PCB.STC32GXXCoreboard-V1.2")
#define SF_VERSION ("C251_V1.0.0_20220905")

// #define __BSP_LED_ENABLED
// #define __BSP_KEY_ENABLED
// #define DBG_ENABLE
// #define DBG_NOLINE
// #define DBG_COLOR
// #define RT_NOASSERT
#include "rtdbg.h"

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
