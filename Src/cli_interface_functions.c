#include "cli_interface_functions.h"

/* This user layer was added in order to keep separate the command interpreter from
 * the list of different functions.
 * */

/*List of functions to read*/
SensorEntry sensor_registry[] = {
    {"sensor1", analog_sensor_1_read}, // from analog sensor 1 file
	{"sensor2", analog_sensor_2_read}, // from analog sensor 2 file
	{"epoch",epoch_get_value},		   // from epoch file
    {NULL, NULL}
};

/*List of functions to write*/
SensorEntry_w sensor_registry_w[] = {
		{"epoch", epoch_set_value},
		{NULL, NULL}
};
