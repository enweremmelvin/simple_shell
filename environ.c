#include "main.h"

/**
 * print_env - print the out variables in the current environment
 * @env: pointer to strings of environment variables to be printed out
 *
 * Return: void
 */

void print_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
