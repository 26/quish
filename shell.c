#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "shell.h"

size_t MAX_LINE_LENGTH = 100;
size_t MAX_ARGUMENT_COUNT = 20;

int main(void) {
    loop();
}

static void loop(void) {
    char line[MAX_LINE_LENGTH];
    char* arguments[MAX_ARGUMENT_COUNT];

    for(;;) {
        write(STDOUT_FILENO, "$ ", 2);

        if (read(STDIN_FILENO, line, MAX_LINE_LENGTH) == -1) {
            perror("quish");
        } else {
            split(line, arguments, MAX_ARGUMENT_COUNT);
            execute(arguments);
        }
    }
}

static void execute(char* args[]) {
    if (args[0] == NULL)
        return;

    if (strcmp(args[0], "cd") == 0) {
        if (chdir(args[1]) < 0)
            perror("quish");
        return;
    }

    if (strcmp(args[0], "exit") == 0)
        exit(EXIT_SUCCESS);

    if (!fork()) {
        if (execvp(args[0], args) < 0)
            perror("quish");

        exit(EXIT_FAILURE);
    }

    int status;
    wait(&status);
}

static void split(char *restrict input, char* buffer[], const size_t bufsize) {
    size_t i = 0;
    char *cur = input;
    while (*++input != '\0' && i < bufsize - 2) {
        if (*input == ' ' || *input == '\n') {
            *input = '\0';
            buffer[i++] = cur;
            cur = input + 1;
        }
    }

    buffer[i++] = NULL;
}
