#ifndef APP_CLI_H_
#define APP_CLI_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "usart_al.h"
#include "cli_interface_functions.h"

#define MAX_CMDLINE_ARGS 5
#define MAX_CMDLINE_LENGTH 50
#define TRANSPARENT_MODE  1
#define COMMAND_LINE_MODE 2

typedef void (*command_fn)(int argc, char *argv[]);

typedef struct {
	char* name;
    command_fn function;
} Command;


/* Main function */
void command_line_interface_init(void);
void command_line_interface(void);
void execute_command(char *line);

/*User interface functions*/
void cmd_help(int argc, char *argv[]);
void cmd_get_sensor_value(int argc, char *argv[]);
void cmd_set_sensor_value(int argc, char *argv[]);

#endif /* APP_CLI_H_ */
