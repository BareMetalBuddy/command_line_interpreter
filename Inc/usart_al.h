#ifndef USART_AL_H
#define USART_AL_H

#include "usart.h"
#include "gpio.h"
#include "rcc.h"
#include "nvic.h"

void usart_al_init(void);
uint16_t usart_al_available(void);
uint8_t usart_al_read(void);

#endif //USART_AL_H
