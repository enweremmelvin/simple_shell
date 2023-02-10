#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
 */

extern char **environ;

int main(int argc __attribute__((unused)), char *argv[])
{
	char *user_input, *command, **arg;
	int exec_ret, fork_id, wait_time;

	arg = NULL;
	wait_time = 2;
	command = malloc(sizeof(char) * MAX_INPUT);

	do {
		if (isatty(0) == 0)
			free(command);

		if (isatty(0) == 1)
			printf("($) ");

		user_input = fgets(command, MAX_INPUT, stdin);
		command = input_parser(command);
		arg = breaker(command);

		printf("%s\n", arg[0]);

		/* checking for malloc */
		if (user_input == NULL)
		{
			free(command);
			free(user_input);
			break;
		}
		if (*command == '\n')
			continue;

/*		command = strndup(command, (strlen(command) - 1));
		printf("%ld\n", strlen(command));
		arg[0] = command;
		arg[1] = NULL;*/
		fork_id = fork();

		if (fork_id == 0)
			exec_ret = execve(arg[0], arg, environ);

		wait(&wait_time);
		if (exec_ret == -1 && fork_id == 0)
			printf("%s: No such file or directory\n", argv[0]);
	} while (true);

	free(command);
	free(arg[0]);

	return (0);
}
