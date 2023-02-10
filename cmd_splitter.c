void breaker(char *command)
{
	int cmd_len, j, i, shifter, next_copy;

	cmd_len = strlen(command);
	j = 0;
	i = 0;
	shifter = 0;
	next_copy = 1;
	while(i < cmd_len)
	{
		if (command[i] == " " || command[i] == '\n')
		{
			arg[j] = strndup(command + shifter, (i - next_copy));
			j++;
			shifter = i + 1;
			next_copy = i + 1;
		}
		i++;
	}
}
