#include "shell.h"

/**
 * bfree - frees a pointer and sets the address to NULL
 * @ptr: the pointer to free
 *
 * Returns: 1 if the pointer was freed, otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
