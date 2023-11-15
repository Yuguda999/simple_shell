#include "shell.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = read_line();
		args = parse_line(line);

		if (!is_builtin(args)) {
			status = execute_command(args);
		} else {
			status = 1; /* Continue shell prompt for built-ins */
		}

		free(line);
		free(args);
	} while (status);

	return (0);
}
