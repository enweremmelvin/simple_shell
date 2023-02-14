#include "main.h"

/**
 * exit_shell - exit the program when the user types in exit as arg[0]
 *
 * @arg: 2 dimensional array of user input
 *
 * Return: user entered return value or 0 if none
 */

void exit_shell(char **arg)
{
	int num;

	if (!arg[1])
		exit(0);

	num = atoi(arg[1]);

	if ((strcmp(arg[0], "exit") == 0) || (strcmp(arg[0], "exit\n") == 0))
		exit(num);
}
