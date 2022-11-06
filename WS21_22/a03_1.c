#include <stdio.h>

int main(void) {
    char    *a = NULL;
    int     *b = NULL, v[17];
    double  *c = NULL;

    printf("\n%ld %ld %ld\n%ld %ld %ld\n\n",
            (long) (a + 1), (long) (b + 1), (long) (c + 1),
            (long) (a + 5), (long) (b + 7), (long) (c + 17));
    
    printf("%p %p %p\n", (void*) v, (void*) &v[0], (void*) &v[10]);

    return 0;
}