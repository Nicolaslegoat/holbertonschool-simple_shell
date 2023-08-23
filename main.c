#include "main.h"


int main(void)
{
	char *input = NULL;
	size_t size = 0;
	ssize_t chars_read = 0;


	while (1)
	{
		printf("$ ");

		chars_read = getline(&input, &size, stdin);
		input[strlen(input) - 1] = '\0';

		if (chars_read == EOF)
		{
			free(input);
			return(0);
		}
		if (chars_read == -1)
			continue;
		split_string(input);
	}
	free(input);
	return (0);
}
