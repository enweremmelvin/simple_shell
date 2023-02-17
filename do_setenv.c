#include "main.h"

/**
 * do_setenv - initialize or modify an environment variable
 *
 * @arg: arguments passed by user
 */

void do_setenv(char **arg)
{
	int i, count;

	count = 0;
	for (i = 0; arg[i]; i++)
		count += 1;
	if (count != 3)
	{
		if (isatty(0) == 1)
		{
			dprintf(STDERR_FILENO,
				"Usage: %s VARIABLE VALUE\n", arg[0]);
			return;
		}
		else
		{
			dprintf(STDERR_FILENO,
				"Usage: %s VARIABLE VALUE\n", arg[0]);
			exit(0);
		}
	} i = setenv(arg[1], arg[2], 1);
	if (i == -1)
	{
		if (isatty(0) == 1)
		{
			dprintf(STDERR_FILENO,
				"Error adding environment variable\n");
			return;
		}
		else
		{
			dprintf(STDERR_FILENO,
				"Error adding environment variable\n");
			exit(0);
		}
	}
	if (isatty(0) != 1)
		exit(1);
}
