/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2016-11-12     Bernard      The first version
 * 2018-05-25     armink       Add simple API, such as LOG_D, LOG_E
 * 2022-09-05     cmm          added support for  c251
 */

/*
 * The macro definitions for debug
 *
 * These macros are defined in static. If you want to use debug macro, you can
 * use as following code:
 *
 * In your C/C++ file, enable/disable DEBUG_ENABLE macro, and then include this
 * header file.
 *
 * #define DBG_TAG           "MOD_TAG"
 * #define DBG_LVL           DBG_INFO
 * #include <rtdbg.h>          // must after of DBG_LVL, DBG_TAG or other options
 *
 * Then in your C/C++ file, you can use LOG_X macro to print out logs:
 * LOG_D("this is a debug log!");
 * LOG_E("this is a error log!");
 */

#ifndef RT_DBG_H__
#define RT_DBG_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef DBG_TAG
#if defined(__FILE_NAME__)
#define DBG_TAG __FILE_NAME__
#elif defined(__MODULE__)
#define DBG_TAG __MODULE__
#else
#define DBG_TAG __FILE__

#endif
#endif

#ifndef DBG_LVL
#define DBG_LVL DBG_LOG
#endif

/* DEBUG level */
#define DBG_ERROR 0
#define DBG_WARNING 1
#define DBG_INFO 2
#define DBG_LOG 3

#ifdef DBG_TAG
#ifndef DBG_SECTION_NAME
#define DBG_SECTION_NAME DBG_TAG
#endif
#else
#ifndef DBG_SECTION_NAME
#define DBG_SECTION_NAME "DBG"
#endif
#endif /* DBG_TAG */

#ifndef __FUNCTION__
    /* compatible with old version */
#define __FUNCTION__ " "
#endif

#ifdef DBG_LVL
#ifndef DBG_LEVEL
#define DBG_LEVEL DBG_LVL
#endif
#else
/* compatible with old version */
#ifndef DBG_LEVEL
#define DBG_LEVEL DBG_WARNING
#endif
#endif /* DBG_LVL */

#ifdef DBG_NOLINE
#define _DBG_LOG_HDR _DBG_LOG_HDR_NOLINE
#else
#define _DBG_LOG_HDR _DBG_LOG_HDR_LINE
#endif

#ifdef DBG_ENABLE

/*
 * The color for terminal (foreground)
 * BLACK    30
 * RED      31
 * GREEN    32
 * YELLOW   33
 * BLUE     34
 * PURPLE   35
 * CYAN     36
 * WHITE    37
 */
#ifdef DBG_COLOR
#define _DBG_COLOR(n) printf("\033[" #n "m")
#define _DBG_LOG_HDR_NOLINE(lvl_name, color_n) \
    printf("\033[" #color_n "m[" lvl_name "/" DBG_SECTION_NAME "] ")
#define _DBG_LOG_HDR_LINE(lvl_name, color_n)                            \
    printf("\033[" #color_n "m[" lvl_name "/" DBG_SECTION_NAME ":%d] ", \
           __LINE__)
#define _DBG_LOG_X_END \
    printf("\033[0m\n")
#else
#define _DBG_COLOR(n)
#define _DBG_LOG_HDR_NOLINE(lvl_name, color_n) \
    printf("[" lvl_name "/" DBG_SECTION_NAME "] ")
#define _DBG_LOG_HDR_LINE(lvl_name, color_n) \
    printf("[" lvl_name "/" DBG_SECTION_NAME ":%d] ", __LINE__)
#define _DBG_LOG_X_END \
    printf("\n")
#endif /* DBG_COLOR */

/*
 * static debug routine
 * NOTE: This is a NOT RECOMMENDED API. Please using LOG_X API.
 *       It will be DISCARDED later. Because it will take up more resources.
 */
#define dbg_log(level,  ...)    \
    if ((level) <= DBG_LEVEL)       \
    {                               \
        switch (level)              \
        {                           \
        case DBG_ERROR:             \
            _DBG_LOG_HDR("E", 31);  \
            break;                  \
        case DBG_WARNING:           \
            _DBG_LOG_HDR("W", 33);  \
            break;                  \
        case DBG_INFO:              \
            _DBG_LOG_HDR("I", 32);  \
            break;                  \
        case DBG_LOG:               \
            _DBG_LOG_HDR("D", 0);   \
            break;                  \
        default:                    \
            break;                  \
        }                           \
        printf( __VA_ARGS__); \
        _DBG_COLOR(0);              \
    }

#define dbg_here                                 \
    if ((DBG_LEVEL) <= DBG_LOG)                  \
    {                                            \
        printf(DBG_SECTION_NAME " Here %s:%d\n", \
               __FUNCTION__, __LINE__);          \
    }

#define dbg_log_line(lvl, color_n,  ...) \
    do                                       \
    {                                        \
        _DBG_LOG_HDR(lvl, color_n);          \
        printf( __VA_ARGS__);          \
        _DBG_LOG_X_END;                      \
    } while (0)

#define dbg_raw(...) printf(__VA_ARGS__);

#else
#define dbg_log(level,  ...)
#define dbg_here
#define dbg_enter
#define dbg_exit
#define dbg_log_line(lvl, color_n,  ...)
#define dbg_raw(...)
#endif /* DBG_ENABLE */

#if (DBG_LEVEL >= DBG_LOG)
#define LOG_D( ...) dbg_log_line("D", 0,  __VA_ARGS__)
#else
#define LOG_D(...)
#endif

#if (DBG_LEVEL >= DBG_INFO)
#define LOG_I( ...) dbg_log_line("I", 32,  __VA_ARGS__)
#else
#define LOG_I(...)
#endif

#if (DBG_LEVEL >= DBG_WARNING)
#define LOG_W( ...) dbg_log_line("W", 33,  __VA_ARGS__)
#else
#define LOG_W(...)
#endif

#if (DBG_LEVEL >= DBG_ERROR)
#define LOG_E( ...) dbg_log_line("E", 31,  __VA_ARGS__)
#else
#define LOG_E(...)
#endif

#define LOG_RAW(...) dbg_raw(__VA_ARGS__)

#define LOG_HEX(type, buff, len)    \
    do                              \
    {                               \
        int i;                      \
        _DBG_LOG_HDR("H", 0);       \
        for (i = 0; i < len; i++)   \
        {                           \
            LOG_RAW(type, buff[i]); \
        }                           \
        _DBG_LOG_X_END;             \
    } while (0)

#ifndef RT_NOASSERT
#define RT_ASSERT(message, expression, handler) \
    do                                          \
    {                                           \
        if (!(expression))                      \
        {                                       \
            LOG_E(message #expression, 0);      \
            handler;                            \
        }                                       \
    } while (0)
#else
#define RT_ASSERT(message, expression, handler) \
    do                                          \
    {                                           \
        if (!(expression))                      \
        {                                       \
            handler;                            \
        }                                       \
    } while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* RT_DBG_H__ */
