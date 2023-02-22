#include "main.h"

/**
 * change_dir - change user directory to specify path by arg[1]
 * @arg: pointer to cd and path name
 *
 * Return: void
 */

void change_dir(char **arg)
{
	int check_err1, check_err2 __attribute__((unused));

	char *store_pwd, *new_pwd, *old_pwd;

	new_pwd = "PWD";
	old_pwd = "OLDPWD";
	if (arg[2])
	{
		printf("%s: too many arguments\n", arg[0]);
		return;
	}
	store_pwd = malloc(sizeof(char) * 256);
	getcwd(store_pwd, 256);
	check_err2 = setenv(new_pwd, store_pwd, 2);
	if (arg[1] == NULL)
	{
		check_err1 = chdir(getenv("HOME"));
		if (check_err1 == 0)
			check_err2 = setenv(old_pwd, store_pwd, 3);
		free(store_pwd);
		return;
	}
	if ((strcmp(arg[1], "-\n") == 0) || (strcmp(arg[1], "-") == 0))
	{
		printf("%s\n", getenv("OLDPWD"));
		chdir(getenv("OLDPWD"));
		check_err2 = setenv(old_pwd, store_pwd, 4);
		free(store_pwd);
		return;
	}
	else
	{
		check_err1 = chdir(arg[1]);
		if (check_err1 != 0)
			printf("%s: %s: No such file or directory\n", arg[0], arg[1]);
		check_err2 = setenv(old_pwd, store_pwd, 5);
		free(store_pwd);
		return;
	}
}
