#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

char **parseInput(char *buffer);
void executeCommand(char **command);

int main(int argc, char **argv)
{
    char *buffer;
    char **command;

    while (1)
    {
        printf("$ ");
        buffer = malloc(sizeof(char) * BUFFER_SIZE);

        if (!buffer)
        {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
        {
            free(buffer);
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        command = parseInput(buffer);

        if (command == NULL)
        {
            free(buffer);
            continue;
        }

        if (strcmp(command[0], "exit") == 0)
        {
            int status = 0;
            if (command[1] != NULL)
                status = atoi(command[1]);

            free(buffer);
            free(command);
            exit(status);
        }

        executeCommand(command);

        free(command);
        free(buffer);
    }

    return 0;
}

char **parseInput(char *buffer)
{
    char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
    if (!tokens)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    char *token;
    int tokenCount = 0;

    token = strtok(buffer, " \t\n");
    while (token != NULL)
    {
        tokens[tokenCount] = strdup(token);
        if (!tokens[tokenCount])
        {
            perror("strdup failed");
            exit(EXIT_FAILURE);
        }
        tokenCount++;
        token = strtok(NULL, " \t\n");
    }
    tokens[tokenCount] = NULL;

    return tokens;
}

void executeCommand(char **command)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execvp(command[0], command) == -1)
        {
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}
