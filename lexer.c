#include "main.h"

/**
 * breaker - pass words in sanitized string to indexes or arg
 *
 * @command: sanitized string
 * @word_count: number of words entered by user (needed for dynamic malloc)
 *
 * Return: nothing
 */

char **breaker(char *command, int word_count)
{
	char **arg;
	int i, j, k;

	pid_t pid __attribute__((unused));

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


	if ((strcmp(arg[0], "exit") == 0) || (strcmp(arg[0], "exit\n") == 0))
	{
		pid = getppid();
		kill(pid, 1);
	}

	if (command_path(arg) == 1)
		return (NULL);

	return (arg);
}
