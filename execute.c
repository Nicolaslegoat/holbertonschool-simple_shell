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

	/*
	if ((access(args[0], X_OK)) != 0)
	{
		return;
	}
*/
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
			args[0] = cmdWithPath;
		}
		if ((execve(args[0], args, NULL)) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&statut);
	}
}
