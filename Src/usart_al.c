#include "usart_al.h"

/*
 * Usart Abstraction Layer.
 * It was implemented in order to hide low level details of usart driver.
 * */

static GPIO_Handler_t cli_tx;
static GPIO_Handler_t cli_rx;
static USART_Handler_t usart1;


/* printf implementation */
int __io_putchar(int ch)
{
	usart_tx(&usart1,(uint8_t)ch);
	return ch;
}

void usart_al_init(void)
{
	rcc_enable_clock(GPIO_PORT_A);
	gpio_init(&cli_tx,GPIOA_BASE_ADDRESS,GPIO_pin_9,GPIO_Alternate_function_output_Push_pull,GPIO_Output_mode_max_speed_10_MHz);
	gpio_config(&cli_tx);
	gpio_init(&cli_rx,GPIOA_BASE_ADDRESS,GPIO_pin_10,GPIO_Floating_input,GPIO_Input_mode);
	gpio_config(&cli_rx);

	rcc_enable_clock(SERIAL_PORT_1);
	usart_init(&usart1,USART1_BASE_ADDRESS,BAUDRATE,0,0,0,0);
	usart_config(&usart1);
	usart_interrupt_enable(&usart1);

	// configure interruption
	nvic_set_irq_priority(2,SERIAL_PORT_1);
	nvic_enable_irq(SERIAL_PORT_1);
}

uint16_t usart_al_available(void)
{
	return usart_available(&usart1);
}

uint8_t usart_al_read(void)
{
	return usart_read(&usart1);
}

void USART1_IRQHandler()
{
	usart_receive(&usart1);
}

