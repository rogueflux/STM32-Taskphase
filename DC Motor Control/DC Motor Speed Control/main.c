#include "main.h"
#include "../ECUAL/DC_MOTOR/DC_MOTOR.h"
 
#define DC_MOTOR1    0
 
ADC_HandleTypeDef hadc1;
 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
 
int main(void)
{
    uint16_t AD_RES = 0;
 
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_ADC1_Init();
    // Calibrate The ADC On Power-Up For Better Accuracy
    HAL_ADCEx_Calibration_Start(&hadc1);
    DC_MOTOR_Init(DC_MOTOR1);
    DC_MOTOR_Start(DC_MOTOR1, DIR_CW, 0);
 
    while (1)
    {
        // Start ADC Conversion
        HAL_ADC_Start(&hadc1);
        // Poll ADC1 Perihperal & TimeOut = 1mSec
        HAL_ADC_PollForConversion(&hadc1, 1);
        // Read The ADC Conversion Result & Map It To PWM DutyCycle
        AD_RES = HAL_ADC_GetValue(&hadc1);
        DC_MOTOR_Set_Speed(DC_MOTOR1, AD_RES>>2);
        HAL_Delay(1);
    }
}
