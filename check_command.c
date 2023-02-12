/**
 * check_command - check if command entered by user contains nothing
 *
 * @command: user inputed command
 *
 * Return: 0 if nothing is found in user command; 1 if something is found
 */

int check_command(char *command)
{
	int i;
	int check;

	i = check = 0;

	while (command[i] != '\0')
	{
		if (command[i] != 32)
			check = 1;
		i++;
	}

	if (check == 0)
		return (1);

	return (0);
}
