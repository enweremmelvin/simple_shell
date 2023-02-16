#include "main.h"

/**
 * check_separator - check for the (;) seperator
 * in an array of recognised keywords
 *
 * @arg: two dimensional array of user input
 * @word_count: number of words in user input
 *
 * Return: 0 on success; 1 on failure
 */

int check_separator(char **arg, int word_count)
{
	int i;

	if (arg == NULL)
		return (1);

	for (i = 0; i < word_count; i++)
	{
		if (strcmp(arg[i], ";") == 0)
		{
			/* here */
			call_execve(arg, i);
			break;
		}
	}

	return (1);
}

/**
 * call_execve - execute commands before and after seperator (;)
 *
 * @arg: two dimensional array of user input
 * @i: row number where seperator (;) was found
 * @j: column number in row where seperator (;) was found
 */

void call_execve(char **arg, int i)
{
	pid_t fork_id;
	char **new_array;
	int index, row, wait_time;
	int exec_ret;

	printf("I get called!\n");

	wait_time = 2;
	new_array = malloc(sizeof(char *) * i);

	for (index = 0; index < i; index++)
		new_array[index] = malloc(sizeof(char) * strlen(arg[index]));

	row = 0;

	while (row < i)
	{
		new_array[row] = arg[row];
		row++;
	}

	printf("%s\n", new_array[0]);
	printf("%s\n", arg[0]);

	fork_id = fork();

	if (fork_id == 0)
		exec_ret = execve(new_array[0], new_array, environ);

	wait(&wait_time);
	if (exec_ret == -1 && fork_id == 0)
		printf("%s: No such file or directory\n", new_array[0]);

	for (index = 0;  index < i; index++)
		free(new_array[index]);
	free(new_array);
	if (isatty(0) != 1) /* exit operations in non-interactive mode*/
		return;

}
