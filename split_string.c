#include "main.h"

/**
 * split_string - use strtk
 * to split a string and put
 * the result in an array
 * @str: a pointer to the string
 * we want to split
 * Return: nothing
 */

void split_string(char *str)
{
	int index = 0;
	char *ar[4096] = { NULL }, *token = NULL;

	if (str == NULL)
		return;

	token = strtok(str, " \t\n");

	while (token != NULL)
	{
		if (token && strlen(token) > 0)
		{
			ar[index] = token;
			index++;
		}
		token = strtok(NULL, " \t\n");
	}


	if (index == 0)
	{
		return;
	}
	if (strcmp(*ar, "exit") == 0 && ar[1] == NULL)
	{
		free(str);
		exit(0);
	}
	execute(ar);
}
