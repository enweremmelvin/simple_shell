#include "shell.h"

/**
 * interactive_program - returns true if the shell is in interactive mode
 * @info: structure address
 *
 * Return: 1 or true if interactive mode, 0 or false otherwise
 */

int interactive_program(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is  delimeter
 * @c: the char to check
 * @delim: the delimeted strings
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic characters
 * @c: The characters to input
 * Return: 1 or true if c is alphabetic, 0 or false otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts  strings to an integer
 * @s: the strings to be converted
 * Return: 0 or false if no numbers in strings, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, result = 0;

	for (i = 0; s[i]; i++)
	{
	if (s[i] == '-')
	{
		sign *= -1;
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result += (s[i] - '0');
	}
	if (result && (s[i + 1] < '0' || s[i + 1] > '9'))
		break;
	}

	return (result * sign);
}
