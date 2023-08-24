#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _getenv - gets the PATH
 * environement
 * @way: a ponter to the path
 * we need to find
 * Return: return the PATH
 */

char *_getenv(char *way)
{
	char **env = environ, *res = NULL;
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], way, strlen(way)) == 0)
		{
			res = env[i];
		}
		i++;
	}
	return (res);
}

/**
 * split_path - split the string
 * containing the path
 * @cmd: the command we want to execute
 * Return: the resulting string
 */

char *split_path(char *cmd)
{
	char *path = NULL, *token = NULL;
	char *result = NULL;
	char way[] = "PATH";
	int path_len = 0;

	path = _getenv(way);

	token = strtok(path, ":");

	while (token != NULL)
	{
		path_len = strlen(cmd) + strlen("/") + strlen(token);
		result = calloc((path_len + 1), sizeof(char));

		strcat(result, token);
		strcat(result, "/");
		strcat(result, cmd);
		if (access(result, F_OK) == 0)
		{
			return (result);
		}
		token = strtok(NULL, ":");
	}

	return (NULL);
}
