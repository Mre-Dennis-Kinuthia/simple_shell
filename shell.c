#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *buffer, **array;
    int counter = 0;

    while (1)
    {
        counter++;
        if (isatty(STDIN_FILENO))
            write(1, "$ ", 2);

        buffer = _getline();

        if (buffer[0] == '\0')
        {
            free(buffer);
            continue;
        }

        array = parser(buffer);

        if (array == NULL)
        {
            free(buffer);
            continue;
        }

        if (strcmp(array[0], "exit") == 0)
        {
            int status = 0;
            if (array[1] != NULL)
                status = atoi(array[1]);

            free(buffer);
            free(array);
            exit(status);
        }

        if (check_cmd(array[0]) == 0)
        {
            exec_builtin(array, counter, argv[0]);
        }
        else
        {
            execute(array, counter, argv, buffer);
        }

        free(array);
        free(buffer);
    }

    return 0;
}

char **parser(char *buffer)
{
    char **cmd, *token;
    int i = 0;

    if (buffer == NULL)
        return NULL;

    cmd = malloc(sizeof(char *) * 1024);
    if (cmd == NULL)
    {
        perror("malloc failed");
        return NULL;
    }

    token = strtok(buffer, " \n");
    while (token != NULL)
    {
        cmd[i] = strdup(token);
        if (cmd[i] == NULL)
        {
            perror("strdup failed");
            free(cmd);
            return NULL;
        }
        i++;
        token = strtok(NULL, " \n");
    }
    cmd[i] = NULL;

    return cmd;
}

void execute(char **array, int counter, char **argv, char *buffer)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return;
    }
    else if (pid == 0)
    {
        if (_strncmp(array[0], "./", 2) != 0 && _strncmp(array[0], "/", 1) != 0)
            path_finder(&array[0]);

        if (execve(array[0], array, environ) == -1)
        {
            printE(counter, array[0], argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
