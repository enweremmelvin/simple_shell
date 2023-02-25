#include "shell.h"

/**
 * fill_memory - fills a memory area with a constant byte value
 * @memory_area: the pointer to the memory area
 * @byte_value: the byte value to fill *memory_area with
 * @num_bytes: the number of bytes to be filled
 *
 * Return: (memory_area) a pointer to the memory area
 */
char *fill_memory(char *memory_area, char byte_value, unsigned int num_bytes)
{
	unsigned int i = 0;

	while (i < num_bytes)
	{
		memory_area[i] = byte_value;
		i++;
	}
	return (memory_area);
}

/**
 * free_string_array - frees an array of strings
 * @string_array: the array of strings
 */
void free_string_array(char **string_array)
{
	char **temp = string_array;

	if (!string_array)
		return;

	while (*string_array)
		free(*string_array++);

	free(temp);
}

/**
 * realloc_memory - reallocates a block of memory
 * @ptr: pointer to the previously allocated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 *
 * Return: pointer to the newly allocated block
 */
void *realloc_memory(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_memory;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	new_memory = malloc(new_size);
	if (!new_memory)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_memory[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (new_memory);
}
