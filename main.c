#include "main.h"

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char *user_input, *command, **arg;
	int exec_ret, fork_id, wait_time, word_count;

	arg = NULL;
	wait_time = 2;
	word_count = 0;
	command = malloc(sizeof(char) * MAX_INPUT);

	do {
		if (isatty(0) == 1)
			printf("($) ");

		user_input = fgets(command, MAX_INPUT, stdin);
		command = input_parser(command, &word_count);
		arg = breaker(command, word_count);

		if (*command == '\0')
			continue;
		if ((arg == NULL) && (isatty(0) == 1))
		{
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		if ((arg == NULL) && (isatty(0) != 1))
		{
			printf("%s: No such file or directory\n", argv[0]);
			exit(1);
		}
		/* checking for malloc */
		if (user_input == NULL)
		{
			free(command);
			break;
		}

		fork_id = fork();
		if (fork_id == 0)
			exec_ret = execve(arg[0], arg, environ);

		wait(&wait_time);
		if (exec_ret == -1 && fork_id == 0)
			printf("%s: No such file or directory\n", argv[0]);
	} while (true);

	return (0);
}
