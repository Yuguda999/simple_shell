#include "shell.h"

/**
 * execute_command - Execute a command in a child process
 * @args: Array of command-line arguments
 * Return: 1 to continue shell prompt, 0 to exit
 */
int execute_command(char **args)
{
	pid_t pid, wpid;
	int status;

	if (args[0] == NULL) {
		return (1); /* Empty command */
	}

	pid = fork();
	if (pid == 0) {
		/* Child process */
		if (execvp(args[0], args) == -1) {
			perror("shell");
		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		perror("shell");
	} else {
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1); /* Continue shell prompt */
}
