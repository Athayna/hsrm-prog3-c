#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void komprimier (char *dest, const char *src) {
    char *res = dest;
    int i, j;
    for(i = 0; i < strlen(src); i++) {
        j = i + 1;
        while (src[i] == src[j]) {
            j++;
        }
        *dest = src[i];
        dest++;
        if ((j - i) > 1) {
            sprintf(dest, "%d", (j - i));
            if ((j - i) < 10) {
                dest++;
            } else {
                dest += 2;
            }
        }
        i = j - 1;
    }
    *dest = '\0';
    dest = res;
}

int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        const char *src = argv[i];
        char *dest = malloc(strlen(src));
        komprimier(dest, src);
        printf("%s\n", dest);
        free(dest);
    }
    return 0;
}