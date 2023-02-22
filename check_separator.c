#include "main.h"

/**
 * check_separator - check for the (;) seperator
 * in an array of recognised keywords
 * @env: environment variables
 * @arg: two dimensional array of user input
 * @word_count: number of words in user input
 *
 * Return: 0 on success; 1 on failure
 */

int check_separator(char **arg, char **env, int word_count)
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
			call_execve(arg, env, i, j);
			j = i + 1;
			count += 1;
		}
		if ((arg[i + 1] == NULL) && (count > 0))
		{
			j = i;
			call_execve(arg, env, i, j);
			count += 1;
			continue;
		}
	}
	if (count == 0)
		return (1);
	if (isatty(0) != 1)
		exit(0);
	return (0);
}

/**
 * call_execve - execute commands before and after seperator (;)
 * @env: environment variables
 * @arg: two dimensional array of user input
 * @i: row number where seperator (;) was found
 * @j: previous index before seperator (;)
 */

void call_execve(char **arg, char **env, int i, int j)
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
	if (j == i)
	{
		while (strcmp(arg[j], ";") != 0)
			j--;
		j += 1;
		while (arg[j] != NULL)
		{
			new_array[row] = arg[j];
			j++;
			row++;
		}
	}
	while (j < i)
	{
		if (arg[j] == NULL)
			break;
		new_array[row] = arg[j];
		j++;
		row++;
	}
	if (builtin_command(new_array, env, 0) == 0)
		return;
	fork_id = fork();
	if (fork_id == 0)
		exec_ret = execve(new_array[0], new_array, environ);
	wait(&wait_time);
	if (exec_ret == -1 && fork_id == 0)
		printf("%s: No such file or directory\n", new_array[0]);
}
