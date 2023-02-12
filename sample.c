#include "main.h"

int main(void)
{
	char *message;

	size_t len;

	ssize_t check;

	len = 0;
        check = _getline(&message, &len, 0);
	printf("%s....%ld.... %ld\n", message, len,check);
	return (0);
}

