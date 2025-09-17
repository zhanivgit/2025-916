

#include "driver_active_buzzer.h"
#include "driver_lcd.h"
#include "driver_timer.h"
#include "stm32f1xx_hal.h"
#include "gpio.h"

/**********************************************************************
 * 函数名称： ActiveBuzzer_Control
 * 功能描述： 有源蜂鸣器控制函数
 * 输入参数： on - 1-响, 0-不响
 * 输出参数： 无
 * 返 回 值： 无
 * 修改日期：      版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/08/04	     V1.0	  韦东山	      创建
 ***********************************************************************/
void ActiveBuzzer_Control(int on)
{
    if (on)
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    else
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
}

/**********************************************************************
 * 函数名称： ActiveBuzzer_Test
 * 功能描述： 有源蜂鸣器测试程序
 * 输入参数： 无
 * 输出参数： 无
 *            无
 * 返 回 值： 无
 * 修改日期        版本号     修改人        修改内容
 * -----------------------------------------------
 * 2023/08/04        V1.0     韦东山       创建
 ***********************************************************************/
void ActiveBuzzer_Test(void)
{
    MX_GPIO_Init();

    while (1)
    {
        LCD_PrintString(0, 0, "ActiveBuzzer ON ");
        ActiveBuzzer_Control(1);
        mdelay(1000);

        LCD_PrintString(0, 0, "ActiveBuzzer OFF");
        ActiveBuzzer_Control(0);
        mdelay(1000);
    }
}


