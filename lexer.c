#include "main.h"

/**
 * breaker - pass words in sanitized string to indexes or arg
 *
 * @command: sanitized string
 * @word_count: number of words entered by user (needed for dynamic malloc)
 * @env: parent environment variable
 *
 * Return: nothing
 */

char **breaker(char *command, int word_count, char **env)
{
	char **arg;
	int i, j, k;

	i = j = k = 0;
	arg = malloc(sizeof(char *) * word_count);

	for (i = 0; i < word_count; i++)
		arg[i] = malloc(sizeof(char) * 50);

	i = 0;
	while (command[i])
	{
		if (command[i] != 32 && command[i] != '\0')
		{
			arg[j][k] = command[i];
			k++;
		}
		else
		{
			j++;
			k = 0;
		}

		i++;
	}
	if (arg[0] == NULL)
		return (NULL);
	if (builtin_command(arg, env) == 0)
	{
		arg[0] = "pass";
		return (arg);
	}
	if ((strcmp(arg[0], "exit") == 0) || (strcmp(arg[0], "exit\n") == 0))
		exit_shell(arg[0], arg[1]);
	if ((strcmp(arg[0], "cd") == 0) || (strcmp(arg[0], "cd\n") == 0))
	change_dir(arg);
	if (command_path(arg) == 1)
		return (NULL);

	return (arg);
}

/**
 * exit_shell - exit the program when the user types in exit as arg[0]
 *
 * @command: first command entered by user
 * @exit_code: program exit code
 *
 * Return: user entered return value or 0 if none
 */

int exit_shell(char *command, char *exit_code)
{
	int num;

	if (!exit_code)
		exit(0);

	num = atoi(exit_code);

	if ((strcmp(command, "exit") == 0) || (strcmp(command, "exit\n") == 0))
		exit(num);

	return (0);
}
