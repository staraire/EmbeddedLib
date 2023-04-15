/**
 * @file STC32G_GPIO_EXTEND
 * COPYRIGHT (C) 2022,  chengmeng_2@outlook.com Co., Ltd.
 * All rights reserved.
 * @brief stc32G gpio driver externd
 * @details 简化stc32G 官方库的宏定义 操作
 *
 * @version ver1.0
 * @date 2022年6月9日
 * @author cmm
 * @note
 */

#ifndef __STC32G_GPIO_EXT_H_
#define __STC32G_GPIO_EXT_H_

#include "stc32G_GPIO.h"

/*!< 拼接GPIO寄存器名称 */
#define PxReg(Pn, PinName) P##Pn##PinName

/*!< 寄存器的常规操作 与或非 */
#define REG_BIT_ADD(Port, Pin) Port &= (Pin)
#define REG_BIT_OR(Port, Pin) Port |= (Pin)

// M1  default 0xFF
// M0  default 0x00
#define PxM1_SET(Port, Pin) REG_BIT_OR(PxReg(Port, M1), Pin)
#define PxM1_RESET(Port, Pin) REG_BIT_ADD(PxReg(Port, M1), ~(Pin))
#define PxM0_SET(Port, Pin) REG_BIT_OR(PxReg(Port, M0), Pin)
#define PxM0_RESET(Port, Pin) REG_BIT_ADD(PxReg(Port, M1), ~(Pin))

//准双向口
#define MODE_IO_PU(Port, Pin)                         \
    {                                                 \
        PxM1_RESET(Port, Pin), PxM0_RESET(Port, Pin); \
    }
#define GPIO_MODE_IO_PU(Port, Pin) MODE_IO_PU(Port, Pin)
//高阻输入
#define MODE_IN_HIZ(Port, Pin)                      \
    {                                               \
        PxM1_SET(Port, Pin), PxM0_RESET(Port, Pin); \
    }
#define GPIO_MODE_IN_HIZ(Port, Pin) MODE_IN_HIZ(Port, Pin)
//漏极开路
#define MODE_OUT_OD(Port, Pin)                    \
    {                                             \
        PxM1_SET(Port, Pin), PxM0_SET(Port, Pin); \
    }
#define GPIO_MODE_OUT_OD(Port, Pin) MODE_OUT_OD(Port, Pin)
//推挽输出
#define MODE_OUT_PP(Port, Pin)                    \
    {                                             \
        PxM1_RESET(Port, Pin), PxM0_SET(Port, Pin); \
    }
#define GPIO_MODE_OUT_PP(Port, Pin) MODE_OUT_PP(Port, Pin)

//========================================================================
//                         端口内部4.1K上拉设置
//========================================================================
//上拉使能 default 0x00
#define GPIO_PULL_UP_ENABLE(Port, Pin) REG_BIT_OR(PxReg(Port, PU), Pin)
//上拉禁止
#define GPIO_PULL_UP_DISABLE(Port, Pin) REG_BIT_ADD(PxReg(Port, PU), ~(Pin))
//========================================================================
//                           端口施密特触发设置
//========================================================================
//施密特触发使能 default 0x00
#define GPIO_ST_ENABLE(Port, Pin) REG_BIT_OR(PxReg(Port, NCS), Pin)
//施密特触发禁止
#define GPIO_ST_DISABLE(Port, Pin) REG_BIT_ADD(PxReg(Port, NCS), ~(Pin))

//========================================================================
//                          端口电平转换速度设置
//========================================================================
//电平转换慢速，相应的上下冲比较小
#define GPIO_SPEED_LOW(Port, Pin) REG_BIT_OR(PxReg(Port, SR), Pin)
//电平转换快速，相应的上下冲比较大
#define GPIO_SPEED_HIGH(Port, Pin) REG_BIT_ADD(PxReg(Port, SR), ~(Pin))

//========================================================================
//                          端口驱动电流控制设置
//========================================================================
//一般驱动能力 default 0xFF
#define GPIO_DRIVE_MEDIUM(Port, Pin) REG_BIT_OR(PxReg(Port, DR), Pin)
//增强驱动能力
#define GPIO_DRIVE_HIGH(Port, Pin) REG_BIT_ADD(PxReg(Port, DR), ~(Pin))

//========================================================================
//                          端口数字信号输入使能
//========================================================================
//使能数字信号输入  default 0xFF
#define GPIO_DIGIT_IN_ENABLE(Port, Pin) REG_BIT_OR(PxReg(Port, IE), Pin)
//禁止数字信号输入
#define GPIO_DIGIT_IN_DISABLE(Port, Pin) REG_BIT_ADD(PxReg(Port, IE), ~(Pin))

//========================================================================
//                          端口数字信号输入使能
//========================================================================
//写入引脚数据  
#define GPIO_WRITE_BIT(Port, Pin, flag) (PxReg(Port, Pin) = flag)
//读取引脚数据
#define GPIO_READ_BIT(Port, Pin) PxReg(Port, Pin)

#endif
