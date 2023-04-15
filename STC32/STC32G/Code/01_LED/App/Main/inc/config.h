#ifndef __CONFIG_H 
#define __CONFIG_H 

/*********************************************************/

//#define MAIN_Fosc		22118400L	//定义主时钟
//#define MAIN_Fosc		12000000L	//定义主时钟
//#define MAIN_Fosc		11059200L	//定义主时钟
//#define MAIN_Fosc		 5529600L	//定义主时钟
#define MAIN_Fosc 24000000L //定义主时钟

/*********************************************************/
#include "stc32g.h"

#if defined __C251__
#include "type_def.h"
#elif defined __C51__
#include <stdint.h>
#include <stdbool.h>
#endif



#endif


