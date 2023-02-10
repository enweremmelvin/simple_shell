#include "main.h"

/**
 * breaker - pass words in sanitized string to indexes or arg
 *
 * @command: sanitized string
 * @arg_string: store individual words in sanitized string at indexes
 *
 * Return: nothing
 */

char **breaker(char *command, int word_count)
{
	char **arg;
	int i, j, k;

	i = j = k = 0;
	arg = malloc(sizeof(char *) * word_count);

	for (i = 0; i < word_count; i++)
		arg[i] = malloc(sizeof(char) * 50);

	i = 0;

	while(command[i])
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

	return (arg);
}
