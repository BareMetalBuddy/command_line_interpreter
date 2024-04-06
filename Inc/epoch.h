#ifndef _EPOCH_H_
#define _EPOCH_H_

#include <stdint.h>
#include <stdio.h>

void epoch_init(void);
void epoch_set_value(uint32_t new_value);
uint32_t epoch_get_value(void);

#endif //_EPOCH_H_
