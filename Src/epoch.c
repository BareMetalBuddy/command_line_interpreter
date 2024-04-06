#include "epoch.h"

static uint32_t epoch_time;

void epoch_init(void){
	epoch_time  = 0;
}

void epoch_set_value(uint32_t new_value ){
	epoch_time = new_value;
}

uint32_t epoch_get_value(void){
	return epoch_time;
}
