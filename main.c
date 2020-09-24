#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int MAX_LINE_LENGTH = 100;

int main(int argc, const char *argv[]) {
    signal(SIGINT, SIG_IGN);
    eval_loop();

    return EXIT_SUCCESS;
}

static void eval_loop(void) {
    char line[MAX_LINE_LENGTH];

    for(;;) {
        fputs("$ ", stdout);

        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            fputs("yeet", stdout);
        }
    }
}


