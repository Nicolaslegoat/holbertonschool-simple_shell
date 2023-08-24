#ifndef __main__h__
#define  __main__h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute(char **args);

void split_string(char *str);

extern char **environ;
char *split_path(char *cmd);
char *_getenv(char *way);
#endif
