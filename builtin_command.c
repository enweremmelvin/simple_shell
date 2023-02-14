#include "main.h"

/**
 * builtin_command - check if arg[0] is a command that should
 *                   be handled without exceve. Initialize a function pointer
 *                   if command is found in list (struct) of commands
 *
 * @arg: two dimensional array of args
 * @env: environment variable from parent
 *
 * Return: 0 on success; 1 on failure
 */

int builtin_command(char **arg, char **env __attribute__((unused)))
{
	int i;

	btn_cmd command[] = {
		{"setenv", do_setenv},
		{"unsetenv", do_unsetenv},
		{"env", print_env},
		{"cd", change_dir}, /* don't change the index of this array */
		{"exit", exit_shell},
		{NULL, NULL}
	};

	for (i = 0; command[i].command != NULL; i++)
	{
		if (strcmp(arg[0], command[i].command) == 0)
		{
			if (i == 2)
			{
				(command[i].handle_function)(env);
				return (0);
			}

			(command[i].handle_function)(arg);
			return (0);
		}
	}

	return (1);
}
