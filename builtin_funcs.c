#include "main.h"

/**
 * __exit - exits the shell
 * @cmd: command
 * @counter: no command executed
 * @argv: argument vector
 * Return: 0 on success, -1 otherwise
 */

int __exit(char **cmd, int counter, char *argv)
{
	int i = 0, status = 0;
	char *ptr;

	if (!cmd[1])
	{
		free(cmd);
		exit(0);
		return (0);
	}

	while (cmd[1][i])
	{
		if (_isdigit(cmd[1][i]) == 0)
		{
			write(2, argv, _strlen(argv));
			write(2, ": ", 2);
			ptr = _itoa(counter);
			write(2, ptr, _strlen(ptr));
			write(2, ": ", 2);
			write(2, cmd[0], _strlen(cmd[0]));
			write(2, ": Illegal number: ", 18);
			write(2, cmd[1], _strlen(cmd[1]));
			write(2, "\n", 1);
			return (-1);
		}
	i++;
	}
	status = _atoi(cmd[1]);
	free(cmd);
	exit(status);
	return (0);
}

/**
 * _env - prints the current environment
 * @cmd: command
 * @counter: command no
 * @argv: argument vector
 * Return: 0 on success, -1 otherwise
 */

int _env(char **cmd, int counter, char *argv)
{
	int i = 0;
	(void)cmd;
	(void)counter;
	(void)argv;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}


/**
 * clear - clears the terminal window
 * @cmd: command
 * @counter: command no
 * @argv: argument vector
 * Return: 0 on success, -1 otherwise
 */

int clear(char **cmd, int counter, char *argv)
{
	(void)cmd;
	(void)counter;
	(void)argv;

	write(1, "\033[1;1H\033[2J", 10);

	return (0);
}
