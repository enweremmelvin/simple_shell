#include "main.h"

/**
 * breaker - pass words in sanitized string to indexes or arg
 *
 * @command: sanitized string
 * @arg_string: store individual words in sanitized string at indexes
 *
 * Return: nothing
 */

char **breaker(char *command)
{
	char **arg;
	int cmd_len, j, i, shifter, next_copy;

	j = 0;
	i = 0;
	shifter = 0;
	next_copy = 1;
	cmd_len = strlen(command);
	arg = malloc(sizeof(char) * cmd_len);

	while(i < cmd_len)
	{
		if (command[i] == ' ' || command[i] == '\0')
		{
			arg[j] = strndup(command + shifter, (i - next_copy));
			j++;
			shifter = i + 1;
			next_copy = i + 1;
		}

		i++;
	}

	return (arg);
}
