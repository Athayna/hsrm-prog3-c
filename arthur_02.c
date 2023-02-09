#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *format(const char *s, const char *a[]) {
    char *res = malloc(strlen(s));
    int num;
    while (*s != '\0') {
        if (*s == '$') {
            s++;
            sscanf(s, "%1d", &num);
            *res = *a[num];
            s++;
        } else {
            *res = *s;
            s++;
        }
        res++;
    }
    return res;
}

int main(void) {
    char *res;
    res = format("$0 und $2.", {"a", "b", "c"});
    printf("%s", res);
    free(res);
    res = format("SOSOSOottern", {"st"});
    printf("%s", res);
    free(res);
    res = format("$17", {"a", "b", "c"});
    printf("%s", res);
    free(res);
    return 0;
}