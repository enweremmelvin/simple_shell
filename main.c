#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
 */
//no changes yet.
int main(int argc __attribute__((unused)), char *argv[])
{
	ssize_t ret;
	char *command, *stripped;
	size_t arg_num;

	int exec_ret, i, fork_id, wait_time;
	char **arg, **env;

	wait_time = 2;

	do {
		printf("($) ");
		ret = getline(&command, &arg_num, stdin);

		arg = malloc(sizeof(command) + 1);
		arg[0] = command;
		arg[1] = NULL;
		env = NULL;

		if (ret == -1)
		{
			dprintf(STDERR_FILENO, "Error getting user input.\n");
			exit(1);
		}

		while (command[i] != '\n')
			i++;

		stripped = malloc(sizeof(char) * i);

		for (i = 0; command[i] != '\n'; i++)
			stripped[i] = command[i];

		fork_id = fork();

		if (fork_id == 0)
			exec_ret = execve(stripped, arg, env);
		wait(&wait_time);

		if (exec_ret == -1 && fork_id == 0)
			printf("%s: No such file or directory\n", argv[0]);

		if (strcmp(command, "exit\n") == 0 ||
		    strcmp(command, "^C\n") == 0)
			exit(1);

		/* pass input to some function to handle */
	} while (true);

	return (0);
}
