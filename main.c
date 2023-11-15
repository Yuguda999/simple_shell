#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/**
 * main - Entry point for the simple shell program.
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	while (1)
	{
		display_prompt();

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			/* End of file (Ctrl+D) */
			break;
		}

		/* Remove newline character */
		command[strcspn(command, "\n")] = '\0';

		/* Tokenize the command and its arguments */
		int i = 0;
		char *token = strtok(command, " ");
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL; /* Ensure the last element is NULL for execvp */

		run_command(args);
	}

	return (0);
}
