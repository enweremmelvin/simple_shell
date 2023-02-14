#include "main.h"

/**
 * _getline - get user text from stdin (aka keyboard)
 *
 * @buffer_add: initial string value
 * @length: length of read string
 * @fd_read: file descriptor being read from
 *
 * Return: number of char read
 */

ssize_t _getline(char **buffer_add, size_t *length, int fd_read)
{
	static unsigned int one_char;
	static ssize_t  char_append, confirm_read; /*for appending, gt realloc*/
	size_t len;
	char char_read, *buffer; /*for single char, array of chars*/

	buffer = *buffer_add; /*initial string value before reading into it*/
	len = *length; /*initial string lenght before reading into it*/
	one_char = 1;  /*constant on byte read*/
	char_append = 0; /*position to append the new char read*/
	do {
		if ((ssize_t)len <= char_append)
		{
			len++;
			buffer = realloc(buffer, len);
		}
		else
		{
			buffer = realloc(buffer, len);
		}
		if (buffer == NULL)
		{
			return (-1);
		}
		confirm_read = (read(fd_read, &char_read, one_char));
		buffer[char_append] = char_read;
		char_read = '\0';
		if (buffer[char_append] == char_read
		    || buffer[char_append] == '\n')
			break;
		if (confirm_read == -1)
			return (confirm_read);
		char_append++;
	} while (true);
	*length = len;
	*buffer_add = buffer;
	return (char_append);
}
