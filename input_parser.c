#include "main.h"

/**
 * input_parser - parse the user input
 * this function makes a consigious string of chars into a token
 *
 * @string: string to be parsed
 *
 * Return: ponter to char
 */

char *input_parser(char *input, int *word_count __attribute__((unused)))
{
	int i, j;
	char *temp;

	i = j = 0;
	*word_count = 0;
	temp = malloc(sizeof(char) * strlen(input));

	while (input[i] != '\0')
	{
		if ((input[i] != 32) && (input[i] != '\n'))
		{
			temp[j] = input[i];
			j++;
		}

		if ((input[i] == 32) && (input[i + 1] != 32) && (temp[j - 1]))
		{
			temp[j] = input[i];
			j++;
		}

		if (
			(!(input[i - 1]) && (input[i] != 32)) ||
			((input[i] == 32) && ((input[i + 1] != 32)))
			)
		{
			*word_count += 1;
		}
		if ((input[i] == 32) && (input[i + 1] == '\n'))
			*word_count -= 1;

		i++;
	}

	return (temp);
}
