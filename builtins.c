#include "shell.h"

/**
 * is_builtin - Check if a command is a built-in shell command
 * @args: Array of command-line arguments
 * Return: 1 if built-in, 0 otherwise
 */
int is_builtin(char **args)
{
	if (args[0] == NULL) {
		return 0; /* Empty command */
	}

	if (strcmp(args[0], "exit") == 0) {
		return shell_exit();
	} else if (strcmp(args[0], "env") == 0) {
		return (shell_env());
	}

	return (0); /* Not a built-in command */
}

/**
 * shell_exit - Handle the exit built-in command
 * Return: 0 to exit the shell
 */
int shell_exit(void)
{
	return (0); /* Terminate shell */
}

/**
 * shell_env - Handle the env built-in command
 * Return: 1 to continue shell prompt
 */
int shell_env(void)
{
	/* Implement env built-in to print current environment */
	/* You can use the `environ` variable to access the environment */
	extern char **environ;
	for (char **env = environ; *env != NULL; env++) {
		printf("%s\n", *env);
	}
	return (1); /* Continue shell prompt after printing environment */
}
