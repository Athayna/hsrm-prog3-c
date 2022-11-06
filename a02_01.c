#include <stdio.h>

int main(void) {
    double x, w1, w2;
    printf("This program calculates the square root of a number.\n");
    printf("Please enter a number:\n");
    scanf("%lf", &x);
    w2 = (1 + x) / 2;
    do {
        w1 = w2;
        w2 = (w1 + x / w1) / 2;
    } while (w1 - w2 > 1E-7);
    printf("The square root of %f is %10.4f\n", x, w2);
    return 0;
}