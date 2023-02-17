#include "main.h"

/**
 * cmd_assigner - insert user cmd to main sequencially
 * @command: user command in the terminal
 *
 * Return: void
 */

int check = 0;
char *exe_cmd;

void cmd_assigner(char *command)
{
	int i, len, start;

	char **change;

	i = 0;
	start = 0;
	change = &command;
	len = strlen(command);
	while(i < len)
	{
		if (command[i] == ';' && (command[i + 1] != '\n' || command[i + 1] != '\0'))
		{
			exe_cmd = strndup(command + start, i - 1);
			check++;
			*change = command + (i + 1);
			return;
		}
		else
		{
			exe_cmd = NULL;
			i++;
		}
	}
}



