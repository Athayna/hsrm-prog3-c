#include <stdio.h>

int romanize(char c, int devider, int arabic) {
    int amount;

    for (amount = arabic / devider; amount > 0; amount--) {
        printf("%c", c);
    }
    arabic %= devider;

    return arabic;
}

int main(void) {
    int arabic;
    printf("This program converts arabic numbers to neo-roman numbers.\n");
    printf("Please enter an arabic number:\n");
    scanf("%d", &arabic);

    arabic = romanize('C', 100, arabic);
    arabic = romanize('L', 50, arabic);
    arabic = romanize('X', 10, arabic);
    arabic = romanize('V', 5, arabic);
    arabic = romanize('I', 1, arabic);

    printf("\n");
    return 0;
}