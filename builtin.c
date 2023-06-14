#include "main.h"

/**
 * check_cmd - checks if command is a builtin command
 *
 * @command: command to check
 * Return: 0 if true, else -1
 */

int check_cmd(char *command)
{
	int i = 0;
	char *array_cmd[] = {"exit", "env", "clear", NULL};

	while (array_cmd[i])
	{
		if (_strcmp(array_cmd[i], command) == 0)
			return (0);

		i++;
	}
	return (-1);
}

/**
 * exec_builtin - executes builtin commands
 * @command: command to execute
 * @counter: command no
 * @argv: argument vector
 * Return: 0 on success, -1 otherwise
 */

int exec_builtin(char **command, int counter, char *argv)
{
	int i = 0;
	built_ins selector[] = {
		{"exit", __exit},
		{"env", _env},
		{"clear", clear},
		{NULL, NULL}
	};

	while ((selector + i)->command)
	{
		if (_strcmp((selector + i)->command, command[0]) == 0)
			return ((selector + i)->func(command, counter, argv));
		i++;
	}
	return (-1);
}
