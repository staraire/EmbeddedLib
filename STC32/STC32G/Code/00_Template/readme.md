# 00_Template

> 模板工程


## 工程结构


```shell
├─App               # 用户程序
│  ├─Dev                # 其它
│  │  └─inc
│  └─Main               # 主程序
│      └─inc
├─Bsp               # 板级支持包
├─Docs              # 工程文档
├─Library           # 主控官方驱动库
├─Module            # 公共组件
├─Pack              # 第三方开源组件包
└─Projects          # 工程相关文件
    └─KEIL              # KEIL工程
```

## config.h 配置说明

事先配置好本工程的内核时钟,能够更加便捷的对时间进行配置
可用于延时函数，定时器等配置

| 宏 | 可选参数 | 配置说明           |
| --- | --- | --- |
| MAIN_Fosc | 22118400L``12000000L``11059200LL``...见官方手册 | 配置设备的内核时钟 |

## main.h 配置说明

这里主要是关于本项目的配置
|宏 |	配置说明 |	说明 |
|---|---|---|
|HF_VERSION |	硬件版本号 |	硬件不更换这里不应该修改|
|SF_VERSION |	软件版本号 |	软件迭代更新|
|__BSP_LED_ENABLED |	使能LED组件 ||	
|__BSP_KEY_ENABLED |	使能key组件 ||	


## rtdbg.h组件配置

|   配置宏   | 可选参数 | 说明                               |
| --- | --- | --- |
| DBG_ENABLE || 调试打印日志的组件，开发过程中需要 |
| DBG_NOLINE || 关闭调试的行号                     |
|  DBG_COLOR  || 启用配置色                         |
| RT_NOASSERT || 不使用断言                         |