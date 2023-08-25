#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "main.h"

/**
 * execute - execute
 * a command
 * @args: a pointer
 * to the arguments of
 * the given command
 * Return: nothing
 */

void execute(char **args)
{
	pid_t pid;
	int statut;
	char *cmdWithPath;

	pid = fork();
	if (pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		cmdWithPath = split_path(args[0]);
		if (cmdWithPath != NULL)
		{
			free(args[0]);
			args[0] = cmdWithPath;
		}
		if ((execve(args[0], args, NULL)) == -1)
		{
			free(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&statut);
	}
}
