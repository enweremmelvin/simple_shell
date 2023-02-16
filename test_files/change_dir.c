#include "main.h"

/**
 * change_dir - change the current directory
 *
 * @arg: 2 dimensional array of user arguments
 */

void change_dir(char **arg)
{
	int i, count, check;
	char *prev_dir, *get_env_val;
	ssize_t max_path;

/**	max_path = 10000;
	prev_dir = malloc(sizeof(char) * max_path);

	getcwd(prev_dir, max_path);
	setenv("PWD", prev_dir, 1);
	get_env_val = getenv("PWD");

	printf("%s\n", get_env_val);*/


	i = count = 0;

	for (; arg[i]; i++)
		count += 1;
	if ((count != 1) && (count != 2))
	{
		printf("Usage: cd || cd [DIRECTORY]\n");
		return;
	}

	if (count == 1)
	{
		check = chdir("/home/");
		if (check == -1)
			dprintf(STDERR_FILENO, "Error changing directory\n");
		return;
	}

	if ((strcmp(arg[1], "-") == 0) || (strcmp(arg[1], "-\n") == 0))
	{
		check = chdir(get_env_val);
		if (check == -1)
			dprintf(STDERR_FILENO, "Error changing directory\n");
		return;
	}

	if (count == 2)
	{
		check = chdir(arg[1]);
		if (check == -1)
			dprintf(STDERR_FILENO, "Error changing directory\n");
		return;
	}
}
