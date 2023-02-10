#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

void schwabify(char *input, char output[]) {
    char *read = input;
    char *write = output;

    while (*read != '\0') {
        if (*read == '.') {
            strcpy(write, ", woisch?");
            write += strlen(", woisch?");
            read++;
        } else if (strncmp(read, "halt", strlen("halt")) == 0) {
            strcpy(write, "heb");
            write += strlen("heb");
            read += strlen("halt");
        } else if (strncmp(read, "ist", strlen("ist")) == 0) {
            strcpy(write, "isch");
            write += strlen("isch");
            read += strlen("ist");
        } else {
            *write = *read;
            write++;
            read++;
        }
    }
    *write = '\0';
}

int main(void) {
    char output[100];
    
    schwabify("Das ist interessant.", output);
    assert(strcmp(output, "Das isch interessant, woisch?") == 0);
    schwabify("Mit     diesem Kleber     sollte es halten, oder?", output);
    assert(strcmp(output, "Mit     diesem Kleber     sollte es heben, oder?") == 0);
    schwabify("haltisthalt. isthaltist...", output);
    assert(strcmp(output, "hebischheb, woisch? ischhebisch, woisch?, woisch?, woisch?") == 0);

    return 0;
}