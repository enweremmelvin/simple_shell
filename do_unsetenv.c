#include "main.h"

/**
 * do_unsetenv - delete an environment variable
 *
 * @arg: arguments passed by user
 */

void do_unsetenv(char **arg)
{
	int i, count;
	char *check_env;

	count = 0;
	for (i = 0; arg[i]; i++)
		count += 1;
	if (count != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s VARIABLE\n", arg[0]);
		if (isatty(0) != 1)
			exit(0);
		return;
	}
	check_env = getenv(arg[1]);
	if (check_env == NULL)
	{
		dprintf(STDERR_FILENO,
			"Environment variable \"%s\" does not exist\n", arg[1]);
		if (isatty(0) != 1)
			exit(0);
		return;
	}
	i = unsetenv(arg[1]);
	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error deleting env variable\n");
		if (isatty(0) != 1)
			exit(0);
		return;
	}
	if (isatty(0) != 1)
		exit(1);
}
