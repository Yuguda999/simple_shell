#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFSIZE 1024
#define DELIM " \n"

/**
 * Function Declarations
 */
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
int is_builtin(char **args);
int shell_exit(void);
int shell_env(void);

#endif /* SHELL_H */
