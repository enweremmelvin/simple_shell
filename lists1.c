#include "shell.h"

/**
 * list_len - determines the length of a linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * list_to_strings - returns an array of strings from a linked list
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t count = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !count)
		return (NULL);

	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);

	for (count = 0; node; node = node->next, count++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < count; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[count] = str;
	}
	strs[count] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * node_starts_with - searches a linked list for a node
 *	whose string starts with a given prefix
 * @head: head pointer to list head
 * @prefix: string to match
 * @c: the next character after the prefix to match,
 *	or -1 to match any character
 *
 * Return: a pointer to the matching node, or NULL if no match is found
 */
list_t *node_starts_with(list_t *head, char *prefix, char c)
{
	char* p = NULL;

	while (head)
	{
		p = starts_with(head->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t count = 0;

	while (head)
	{
		if (head == node)
			return (count);
		head = head->next;
		count++;
	}
	return (-1);
}
