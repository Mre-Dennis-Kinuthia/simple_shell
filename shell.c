#include "main.h"

/**
 * main - execve example
 *
 *@argc: number of arguments
 *@argv: argument vectors
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	char *buffer, **array, c;
	int counter = 0;

	(void)argc;
	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		buffer = _getline();

		c = buffer[0];

		if (c == '\0')
			continue;
		array = parser(buffer);
		if (check_cmd(array[0]) == 0)
		{
			exec_builtin(array, counter, argv[0]);
			free(array);
			free(buffer);
			array = NULL;
			buffer = NULL;
			continue;
		}
		else
			execute(array, counter, argv, buffer);
		free(array);
		free(buffer);
	}
	return (0);
}
/**
*parser- parses the commmand input
*
*@buffer: string containing command
*
*Return: Parsed command
*/
char **parser(char *buffer)
{
	char **cmd, *token;
	int i;

	if (buffer == NULL)
		return (NULL);

	token = strtok(buffer, " \n");
	if (token == NULL)
		return (NULL);

	cmd = malloc(sizeof(char *) * 1024);

	i = 0;
	while (token)
	{
		cmd[i++] = token;
		token = strtok(NULL, " \n");
	}
	cmd[i] = NULL;
	return (cmd);
}
/**
*execute - executes commands within the shell
*
*@array: parsed command
*@counter: command no
*@argv: commandline arguments
*@buffer:buffer containing input
*/
void execute(char **array, int counter, char **argv, char *buffer)
{
	int status;

	if (fork() != 0)
	{
		wait(&status);
	}
	else
	{
		if (_strncmp(array[0], "./", 2) != 0 && _strncmp(array[0], "/", 1) != 0)
			path_finder(&array[0]);

		if (execve(*array, array, environ) == -1)
		{
			printE(counter, array[0], argv[0]);
			free(array);
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}
}
