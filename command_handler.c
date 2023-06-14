#include "command_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char **parseCommand(char *command) {
    char **args = malloc(sizeof(char *) * 1024);
    if (args == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(command, " \t\n");
    int i = 0;
    while (token != NULL) {
        args[i] = strdup(token);
        if (args[i] == NULL) {
            perror("strdup failed");
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    return args;
}

void executeSingleCommand(char **command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(command[0], command) == -1) {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void executeCommands(char **commands) {
    int i = 0;

    while (commands[i] != NULL) {
        char **command = parseCommand(commands[i]);

        if (strcmp(command[0], "setenv") == 0) {
            setenv_builtin(command);
        } else if (strcmp(command[0], "unsetenv") == 0) {
            unsetenv_builtin(command);
        } else {
            executeSingleCommand(command);
        }

        free(command);
        i++;
    }
}
