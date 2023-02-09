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

	do {
		printf("($) ");
		ret = getline(&command, &arg_num, stdin);

		if (ret == -1)
		{
			dprintf(STDERR_FILENO, "Error getting user input.\n");
			exit(1);
		}

		if (strcmp(command, "exit\n") == 0)
			exit(1);

		/* pass input to some function to handle */
	} while (true);

	return (0);
}
