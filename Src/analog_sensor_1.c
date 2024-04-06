#include "analog_sensor_1.h"

static GPIO_Handler_t analog_sensor_1_pin;
static ADC_Handler_t adc1;

/* Wraps low-level layer into a user layer. In this case a generic analog sensor*/
/* It is necessary configure first the GPIO pin for ADC channel that we want to use*/
/* In this case the configuration was the GPIO pin PC0 for ADC channel 10 */

void analog_sensor_1_init(void)
{
	rcc_enable_clock(GPIO_PORT_C);
	gpio_init(&analog_sensor_1_pin,GPIOC_BASE_ADDRESS,GPIO_pin_0,GPIO_Analog_Mode,GPIO_Input_mode);
	gpio_config(&analog_sensor_1_pin);

	rcc_enable_clock(ADC1);
	adc_init(&adc1,ADC1_BASE_ADDRESS,10);
}


uint32_t analog_sensor_1_read(void)
{
	return adc_read(&adc1);
}
