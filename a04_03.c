#include <stdio.h>
#include <ctype.h>
#include <string.h>

void censor(char *line, int argc, char *argv) {
    int i;
    for (i = 0; i < argc; i++) {
        while (strcasestr(line, argv[argc])) {
            strcasestr(line, argv[argc]);
        }
    }
}

int main(int argc, char *argv[]) {
    char line[200] = {0};

    while (fgets(line, 199, stdin)) {
        censor(line, argc - 1, argv + 1);
    }

    return 0;
}