#include <stdio.h>

int main(void) {
    double x, w, w2, abstand;
    scanf("%lf", &x);

    w = (1 + x) / 2;

    do {
        w2 = (w + x / w) / 2;

        abstand = w - w2;

        if (abstand < 0)
            abstand = abstand * (-1);

        w = w2;

    } while (abstand > (1 / 10000000));

    printf("\nResult: %6.4f\n\n", w);

    return 0;
}