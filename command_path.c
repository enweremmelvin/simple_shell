#include "main.h"

/**
 * command_path - change the entered command to its path
 *
 * @command: 2 dimensional array of entered commands
 *
 * Return: 0 on success and 1 on failure
 */

int command_path(char **command)
{
	int i, j, check;
	put_path command_arr[] = {
		{"ls", "/bin/ls"},
		{"pwd", "/bin/pwd"},
		{"cp", "/bin/cp"},
		{NULL, NULL}
	};

	i = j = check = 0;

	for (; command[i]; i++)
	{
		for (; command_arr[j].command != NULL; j++)
		{
			if (strcmp(command[i], command_arr[j].command) == 0)
			{
				check = 1;
				command[i] = command_arr[j].path;
				break;
			}
		}
	}

	if (check == 0)
		return (1);

	return (0);
}
