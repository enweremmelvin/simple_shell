#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char **arg, **env;
	char *user_input, *command, *strip;
	int i, exec_ret, fork_id, wait_time;

	wait_time = 2;
	command = malloc(sizeof(char) * MAX_INPUT);

	do {
		if (isatty(0) == 1)
		{
			printf("($) ");
		}
		user_input = fgets(command, MAX_INPUT, stdin);
		if (user_input == NULL)
			break;
		strip = malloc(sizeof(char) * strlen(command));
		for (i = 0; command[i] != '\n'; i++)
			strip[i] = command[i];
		i = 0;
		if (!(strip[i]))
			continue;
		arg = malloc(strlen(user_input) + 1);
		arg[0] = user_input;
		arg[1] = NULL;
		env = NULL;

		fork_id = fork();
		if (fork_id == 0)
			exec_ret = execve(strip, arg, env);

		wait(&wait_time);
		if (exec_ret == -1 && fork_id == 0)
			printf("%s: No such file or directory\n", argv[0]);
	} while (true);

	return (0);
}
