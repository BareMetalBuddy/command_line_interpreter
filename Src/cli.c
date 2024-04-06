#include "cli.h"

/*
 * A pure C - and independent of hardware -implementation for Command line Interpreter library.
 */

static uint8_t input_data_from_user[MAX_CMDLINE_LENGTH];
static uint8_t in = 0;

/*List of supported commands*/
Command command_table[] = {
    {"help", cmd_help},
	{"get_value",cmd_get_sensor_value},
	{"set_value",cmd_set_sensor_value},
    {NULL, NULL}
};

/*Configure all hardware necessary for serial port used by command line interface*/
void command_line_interface_init(void)
{
	usart_al_init();
}

void command_line_interface(void)
{
	in = 0;
	memset(input_data_from_user,0,sizeof(input_data_from_user));
	while(usart_al_available()>0){
		input_data_from_user[in] = usart_al_read();
	    if(input_data_from_user[in] != '\r'){
	    	in++;
	    }
	    else
	    {
	    	input_data_from_user[in] = '\0';
	    	in = 0;
	    	if (strlen((const char *)input_data_from_user) > 0){
	    		execute_command((char *)input_data_from_user);
	    	}
	    }
	}
}

void execute_command(char *line)
{
    char *argv[MAX_CMDLINE_ARGS];
    int argc = 0;

    char *token = strtok(line, " ");
    while (token != NULL && argc < MAX_CMDLINE_ARGS) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    for (Command *command = command_table; command->name != NULL; command++) {
        if (strcmp(argv[0], command->name) == 0) {
            command->function(argc, argv);
            return;
        }
    }

    printf("unknown command: %s\n", argv[0]);
}

/*Help Command : displayed all supported commands*/
void cmd_help(int argc, char *argv[]) {
    printf("Available commands:\n");
    for (Command *command = command_table; command->name != NULL; command++) {
        printf("  %s\n", command->name);
    }
}

void cmd_get_sensor_value(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: get_value <sensor_name>\n");
        return;
    }
    char* sensor_name = argv[1];
    for (int i = 0; sensor_registry[i].sensor_name != NULL; i++) {
        if (strcmp(sensor_registry[i].sensor_name, sensor_name) == 0) {
            uint32_t value = sensor_registry[i].read_sensor();
            printf("%s value: %lu\n", sensor_name, value);
            return;
        }
    }
    printf("Sensor not found\n");
}

void cmd_set_sensor_value(int argc, char *argv[]){
	if (argc < 3) {
		printf("Usage: set_value <sensor_name> <value>\n");
	    return;
	}

	char* sensor_name = argv[1];
	for (int i = 0; sensor_registry_w[i].sensor_name != NULL; i++) {
		if (strcmp(sensor_registry_w[i].sensor_name, sensor_name) == 0) {
			uint32_t valorEpoch = (uint32_t)strtoul(argv[2], NULL, 10);
	        sensor_registry_w[i].write_sensor(valorEpoch);
	        printf("set value: %s %lu\n", sensor_name, valorEpoch);
	        return;
	    }
	}
	printf("Sensor not found\n");
}

