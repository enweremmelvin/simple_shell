#include "main.h"

/**
 * do_unsetenv - delete an environment variable
 *
 * @arg: arguments passed by user
 */

void do_unsetenv(char **arg)
{
	int i, count;

	count = 0;
	for (i = 0; arg[i]; i++)
		count += 1;
	if (count != 2)
	{
		if (isatty(0) == 1)
		{
			dprintf(STDERR_FILENO, "Usage: %s VARIABLE\n", arg[0]);
			return;
		}
		else
		{
			dprintf(STDERR_FILENO, "Usage: %s VARIABLE\n", arg[0]);
			exit(0);
		}
	} i = unsetenv(arg[1]);
	if (i == -1)
	{
		if (isatty(0) == 1)
		{
			dprintf(STDERR_FILENO, "Error deleting env variable\n");
			return;
		}
		else
		{
			dprintf(STDERR_FILENO, "Error adding env variable\n");
			exit(0);
		}
	}
	if (isatty(0) != 1)
		exit(1);
}
