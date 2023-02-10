#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *format(const char *s, const char *a[]) {
    char *res = malloc(strlen(s));
    char *ret = res;
    int num;
    while (*s != '\0') {
        if (*s == '$') {
            s++;
            sscanf(s, "%1d", &num);
            *res = *a[num];
            strcpy(res, a[num]);
            res += strlen(a[num]);
            s++;
        } else {
            *res = *s;
            s++;
            res++;
        }
    }
    *res = '\0';
    return ret;
}

int main(void) {
    const char *s1 = "$0 und $2.";
    const char *a1[] = {"a", "b", "c"};
    const char *s2 = "$0$0$0ottern";
    const char *a2[] = {"st"};
    const char *s3 = "$17";
    const char *a3[] = {"a", "b", "c"};

    char *res = format(s1, a1);
    printf("%s\n", res);
    assert(strcmp(res, "a und c.") == 0);
    free(res);

    res = format(s2, a2);
    printf("%s\n", res);
    assert(strcmp(res, "stststottern") == 0);
    free(res);

    res = format(s3, a3);
    printf("%s\n", res);
    assert(strcmp(res, "b7") == 0);
    free(res);

    return 0;
}