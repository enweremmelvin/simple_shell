#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	ssize_t ret;
	char *command;
	size_t arg_num;

	do
	{
		printf("($) ");
		ret = getline(&command, &arg_num, stdin);

		if (ret == -1)
		{
			dprint(STDERR_FILENO, "Error getting user input.\n");
			exit();
		}

		if (strcmp(command, "exit") == 0)
			exit();

		/* pass input to some function to handle */
	} while (true);

	return (0);
}
