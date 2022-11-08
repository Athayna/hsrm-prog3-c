#include <stdio.h>

int main(void) {
    char *a = NULL;
    int *b = NULL, v[17];
    double *c = NULL;
    printf("\n%ld %ld %ld\n%ld %ld %ld\n\n",
    /*moves the previously set pointers by once their length and prints that distance (sizeof)*/
    (long) (a+1), (long)(b+1), (long)(c+1),
    /*multiplies that variable size by certain values and prints them*/
    (long) (a+5), (long)(b+7), (long)(c+17));
    /*prints the address of pointers, refering to an int array which again shows the size of an int*/
    printf("%p %p %p\n", (void*)v, (void*)&v[0], (void*)&v[10]);
    return 0;
}