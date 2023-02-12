#include "main.h"

/**
 * check_input_mode - check whether our program is in interactive
 *                    or non-interactive mode
 *
 * @arg: user command made into tokens with the breaker function
 * @fcommand: first argument passed to program (executable name)
 * @word_count: number of words entered by user
 *
 * Return: 1 if in non-interactive mode
 */

int check_input_mode(char **arg, char *fcommand, int word_count)
{
	(void) word_count;

	if ((arg == NULL) && (isatty(0) == 1)) /* interactive mode */
	{
		printf("%s: No such file or directory\n", fcommand);
		return (1);
	}
	if ((arg == NULL) && (isatty(0) != 1)) /* non-interactive mode */
	{
		printf("%s: No such file or directory\n", fcommand);
		exit(1);
	}

	return (0);
}

/**
 * free_arg - free memory allocated to 2 dimensional array (arg)
 *
 * @arg: two dimensional array to be filled
 * @word_count: number of rows in arg
 */

void free_arg(char **arg, int word_count)
{
	int i;

	if (arg != NULL)
	{
		for (i = 0; i < word_count; i++)
			free(arg[i]);
		free(arg);
	}
}
