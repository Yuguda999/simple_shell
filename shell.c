#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
	fflush(stdout);
}

/**
 * run_command - Execute the given command.
 * @args: Array of strings containing the command and its arguments.
 */
void run_command(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("simple_shell");
	}
	else if (pid == 0)
	{
		/* Child process */
		execvp(args[0], args);
		perror("simple_shell");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);
	}
}
