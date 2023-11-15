#ifndef SHELL_H
#define SHELL_H

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void);

/**
 * run_command - Execute the given command.
 * @args: Array of strings containing the command and its arguments.
 */
void run_command(char **args);

#endif /* SHELL_H */
