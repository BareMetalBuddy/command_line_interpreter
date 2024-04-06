#ifndef CLI_INTERFACE_FUNCTONS_H
#define CLI_INTERFACE_FUNCTONS_H

#include <stdint.h>
#include <stdio.h>
#include "analog_sensor_1.h"
#include "analog_sensor_2.h"
#include "epoch.h"

typedef struct {
    char* sensor_name;
    uint32_t (*read_sensor)(void);
} SensorEntry;

extern SensorEntry sensor_registry[];


typedef struct {
	char* sensor_name;
	void (*write_sensor)(uint32_t value);
} SensorEntry_w;

extern SensorEntry_w sensor_registry_w[];

#endif // CLI_INTERFACE_FUNCTONS_H
