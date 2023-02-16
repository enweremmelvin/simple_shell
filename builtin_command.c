#include "main.h"

/**
 * builtin_command - check if arg[0] is a command that should
 *                   be handled without exceve. Initialize a function pointer
 *                   if command is found in list (struct) of commands
 *
 * @arg: two dimensional array of args
 * @env: environment variable from parent
 * @word_count: number of words entered by user
 *
 * Return: 0 on success; 1 on failure
 */

int builtin_command(char **arg, char **env, int word_count)
{
	int i;

	btn_cmd command[] = {
		{"env", print_env}, /* don't change the index of this array */
		{"setenv", do_setenv},
		{"unsetenv", do_unsetenv},
		{"cd", change_dir},
		{NULL, NULL}
	};

	(void) word_count;

	for (i = 0; command[i].command != NULL; i++)
	{
		if (strcmp(arg[0], command[i].command) == 0)
		{
			if (i == 0)
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
