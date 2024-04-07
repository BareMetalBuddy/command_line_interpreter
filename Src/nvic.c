#include "nvic.h"

void nvic_enable_irq(uint8_t module)
{
	switch(module)
	{
	case SERIAL_PORT_1:
		NVIC_ENABLE_INTERRUPT_USART1();
		break;

	case SERIAL_PORT_2:
		NVIC_ENABLE_INTERRUPT_USART2();
		break;

	case SERIAL_PORT_3:
		break;

	case BASIC_TIMER_6:
		break;

	case BASIC_TIMER_3:
		NVIC_ENABLE_INTERRUPT_TIM3();
		break;

	default:
		break;
	}
}

void nvic_disable_irq(uint8_t module)
{
	switch(module)
	{
	case SERIAL_PORT_1:
		break;

	case SERIAL_PORT_2:
		break;

	case SERIAL_PORT_3:
		break;

	case BASIC_TIMER_6:
		break;

	case BASIC_TIMER_3:
		NVIC_DISABLE_INTERRUPT_TIM3();
		break;

	default:
		break;
	}


}

void nvic_set_irq_priority(uint8_t module ,uint32_t priority)
{
	switch(module)
	{
	case SERIAL_PORT_1:
		NVIC_SET_INTERRUPT_PRIORITY_USART1(priority);
		break;

	case SERIAL_PORT_2:
		NVIC_SET_INTERRUPT_PRIORITY_USART2(priority);
		break;

	case SERIAL_PORT_3:
		break;

	case BASIC_TIMER_6:
		break;

	case BASIC_TIMER_3:
		NVIC_SET_INTERRUPT_PRIORITY_TIM3(priority);
		break;

	default:
		break;
	}
}
