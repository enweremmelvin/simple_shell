#include "main.h"

int main(void)
{
	char *check = malloc(sizeof(char) * 120);
	getcwd(check, 120);
	//char *s = "-";
	int error = chdir(getenv("OLDPWD"));

	printf("%s\n... %d\n",getenv("OLDPWD"), error);
	return (0);
}
