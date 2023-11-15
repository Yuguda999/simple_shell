#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point for the simple shell program.
 * Return: Always 0.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

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

		run_command(command);
	}

	return (0);
}
