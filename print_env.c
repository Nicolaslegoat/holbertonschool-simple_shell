#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 *_print_env - prints environement
 *Return: nothing
 */

void _print_env(void)
{
	char **env = environ;

	printf("%s\n", env[0]);
}
