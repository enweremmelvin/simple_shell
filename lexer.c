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
	arg = malloc(sizeof(char *) * (word_count + 1));

	for (i = 0; i < word_count; i++)
		arg[i] = malloc(sizeof(char) * 50);

	i = 0;
	while (command[i]) /* manual strtok */
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
	arg[j + 1] = NULL;

	if (breaker_function_calls(arg, env, word_count) == 0)
		return (arg);
	else
		return (NULL);
}


/**
 * breaker_function_calls - function for calling external functions
 * in the breaker function. This function was made to help comply with
 * the betty style of not more than 40 lines in a function
 *
 * @arg: two dimensional array of user input
 * @env: parent environment variable
 * @word_count: number of words entered by the user
 *
 * Return: 0 when we want to return (arg) in breaker;
 *         1 when we want to return (NULL) in breaker.
 */

int breaker_function_calls(char **arg, char **env, int word_count)
{
	if (arg[0] == NULL)
		return (1);

	if (builtin_command(arg, env, word_count) == 0)
	{
		arg[0] = "pass";
		return (0);
	}

	if ((strcmp(arg[0], "exit") == 0) || (strcmp(arg[0], "exit\n") == 0))
		exit_shell(arg);

	if (command_path(arg) == 1)
		return (1);

	if (check_separator(arg, env, word_count) == 0)
	{
		arg[0] = "pass";
		return (0);
	}

	return (0);
}
