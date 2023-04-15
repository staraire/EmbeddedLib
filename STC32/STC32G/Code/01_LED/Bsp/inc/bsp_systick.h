/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_SYSTICK_H_
#define __BSP_SYSTICK_H_
/* Private includes ----------------------------------------------------------*/
#include "stdint.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------------*/
void Tick_init(void);
void Tick_start(void);
void Tick_stop(void);
void Tick_reset(void);
uint32_t Tick_GetClock();
void Tick_Delay(uint32_t ms);

#endif //__BSP_SYSTICK_H_
