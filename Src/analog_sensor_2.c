#include "analog_sensor_1.h"

static GPIO_Handler_t analog_sensor_2_pin;
static ADC_Handler_t adc2;


void analog_sensor_2_init(void)
{
	rcc_enable_clock(GPIO_PORT_C);
	gpio_init(&analog_sensor_2_pin,GPIOC_BASE_ADDRESS,GPIO_pin_1,GPIO_Analog_Mode,GPIO_Input_mode);
	gpio_config(&analog_sensor_2_pin);

	rcc_enable_clock(ADC2);
	adc_init(&adc2,ADC2_BASE_ADDRESS,11);
}


uint32_t analog_sensor_2_read(void)
{
	return adc_read(&adc2);
}
