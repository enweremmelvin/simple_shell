#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *str)
{
	int length = 0;

	if (!str)
	return (0);

	while (*str++)
	length++;

	return (length);
}

/**
 * string_compare - Compares two strings lexicographically.
 * @str1: the first strang
 * @str2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int string_compare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
	if (*str1 != *str2)
	return (*str1 - *str2);
	str1++;
	str2++;
	}

	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * string_starts_with - Checks if haystack starts with needle.
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *string_starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
	if (*needle++ != *haystack++)
		return (NULL);
	}

	return ((char *)haystack);
}

/**
 * string_concat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *string_concat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	dest++;

	while (*src)
	*dest++ = *src++;

	*dest = *src;

	return (ret);
}
