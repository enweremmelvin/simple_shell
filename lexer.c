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
	if (arg[0] == NULL)
		return (NULL);
	if (builtin_command(arg, env) == 0)
	{
		arg[0] = "pass";
		return (arg);
	}
	if (command_path(arg) == 1)
		return (NULL);

	return (arg);
}
