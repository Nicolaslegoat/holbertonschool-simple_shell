#include "main.h"

void split_string(char *str)
{
	int index = 0;
	char *ar[4096] = { NULL }, *token = NULL;

	token = strtok(str, " ");

	while (token != NULL)
	{

		ar[index] = token;
		index++;
		token = strtok(NULL, " ");
	}
	execute(ar);
}
