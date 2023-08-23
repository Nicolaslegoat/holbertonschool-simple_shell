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

	token = strtok(str, " ");

	while (token != NULL)
	{

		ar[index] = token;
		index++;
		token = strtok(NULL, " ");
	}
	execute(ar);
}
