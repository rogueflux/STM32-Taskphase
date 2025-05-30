// The Number OF Servo Motors To Be Used In The Project
#define SERVO_NUM  1
 
typedef struct
{
    GPIO_TypeDef * SERVO_GPIO;
    uint16_t       SERVO_PIN;
    TIM_TypeDef*   TIM_Instance;
    uint32_t*      TIM_CCRx;
    uint32_t       PWM_TIM_CH;
    uint32_t       TIM_CLK;
    float          MinPulse;
    float          MaxPulse;
}SERVO_CfgType;
 
/*-----[ Prototypes For All Functions ]-----*/
 
void SERVO_Init(uint16_t au16_SERVO_Instance);
 
void SERVO_MoveTo(uint16_t au16_SERVO_Instance, float af_Angle);
 
void SERVO_RawMove(uint16_t au16_SERVO_Instance, uint16_t au16_Pulse);
 
uint16_t SERVO_Get_MaxPulse(uint16_t au16_SERVO_Instance);
 
uint16_t SERVO_Get_MinPulse(uint16_t au16_SERVO_Instance);
 
void SERVO_Sweep(uint16_t au16_SERVO_Instance);
