#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "builtins.h"

int setenv_builtin(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return 1;
    }

    if (setenv(args[1], args[2], 1) == -1) {
        perror("setenv failed");
        return 1;
    }

    return 0;
}

int unsetenv_builtin(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return 1;
    }

    if (unsetenv(args[1]) == -1) {
        perror("unsetenv failed");
        return 1;
    }

    return 0;
}
