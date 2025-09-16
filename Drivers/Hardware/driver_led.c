
#include "driver_led.h"
#include "driver_timer.h"

#include "gpio.h"

int Led_Control(int which, int on)
{
    if (on)
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    else
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    return 0;
}

void Led_Test(void)
{   MX_GPIO_Init();
    while (1)
    {
        Led_Control(LED_GREEN, 1);
        mdelay(500);

        Led_Control(LED_GREEN, 0);
        mdelay(500);
    }
}

