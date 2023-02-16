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
	int i, j, count;

	(void) word_count;
	j = count = 0;

	if (arg == NULL)
		return (1);

	for (i = 0; arg[i] != NULL; i++)
	{
		if ((strcmp(arg[i], ";") == 0))
		{
			call_execve(arg, i, j);
			j = i + 1;
			count += 1;
		}
	}
	printf("Value of i = %d\n", i);
	if (count == 0)
		return (1);

	return (0);
}

/**
 * call_execve - execute commands before and after seperator (;)
 *
 * @arg: two dimensional array of user input
 * @i: row number where seperator (;) was found
 */

void call_execve(char **arg, int i, int j)
{
	int exec_ret;
	pid_t fork_id;
	char **new_array;
	int index, row, wait_time;

	wait_time = 2;
	new_array = malloc(sizeof(char *) * i);

	for (index = 0; index < (i - j); index++)
		new_array[index] = malloc(sizeof(char) * strlen(arg[index]));

	row = 0;
	index = j;

	while (j < i)
	{
		new_array[row] = arg[j];
		j++;
		row++;
	}

	fork_id = fork();

	if (fork_id == 0)
		exec_ret = execve(new_array[0], new_array, environ);

	wait(&wait_time);
	if (exec_ret == -1 && fork_id == 0)
		printf("%s: No such file or directory\n", new_array[0]);

	if (isatty(0) != 1) /* exit operations in non-interactive mode*/
		return;
}
