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
	char *command, **arg;
	int exec_ret, fork_id, wait_time, word_count;

	arg = NULL;
	wait_time = 2;
	word_count = 0;
	command = malloc(sizeof(char) * MAX_INPUT);

	do {
		if (isatty(0) == 1)
			printf("($) ");

		fgets(command, MAX_INPUT, stdin);
		command = input_parser(command, &word_count);
		arg = breaker(command, word_count, environ);

		if ((check_command(command) == 1) && (isatty(0) != 1))
			exit(0);
		if (check_command(command) == 1) /* check if command is empty*/
			continue;
		if (check_input_mode(arg, argv[0], word_count) == 1)
			continue;

		fork_id = fork();
		if (fork_id == 0)
			exec_ret = execve(arg[0], arg, environ);

		wait(&wait_time);
		if (exec_ret == -1 && fork_id == 0)
			printf("%s: No such file or directory\n", argv[0]);
	} while (true);

	return (0);
}
