#include "epoch.h"

static uint32_t epoch_time;
TIMx_Handler_t timx_handler_t3; // to configure timer 3

void epoch_init(void){

	epoch_time  = 0; 	// initial value for epoch time

	/*timer 3 is set to do an interruption each 1 second*/
	rcc_enable_clock(BASIC_TIMER_3);
	timx_init(&timx_handler_t3,TIM3_BASE_ADDRESS,TIM3_PRESCALER_VALUE_FOR_1000MS,TIM3_RELOAD_VALUE_FOR_1000MS);
	timx_config(&timx_handler_t3);
	timx_update_interrupt(&timx_handler_t3, 1);
	nvic_set_irq_priority(BASIC_TIMER_3,1);
	nvic_enable_irq(BASIC_TIMER_3);
}

void epoch_set_value(uint32_t new_value ){
	nvic_disable_irq(BASIC_TIMER_3);
	epoch_time = new_value;
	nvic_enable_irq(BASIC_TIMER_3);
}

uint32_t epoch_get_value(void){
	nvic_disable_irq(BASIC_TIMER_3);
	uint32_t e = epoch_time;
	nvic_enable_irq(BASIC_TIMER_3);
	return e;
}

void TIM3_IRQHandler(void)
{
	if ((timx_handler_t3.timx->TIMx_SR) & 0x01) {
		(timx_handler_t3.timx->TIMx_SR) &= ~0x01;
	}
	epoch_time++;
}




