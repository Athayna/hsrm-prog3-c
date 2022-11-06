#include <stdio.h>

/*prints unsigned int in binary form*/
void schreibbit(unsigned z) {
    int i;
    for(i = 15; i >= 0; i--) {
        if (z >= (1 << i)) {
            printf("1");
            z %= (1 << i);
        } else {
            printf("0");
        }
    }
    printf("\n");
}

/*reads integer from keyboard input in a binary form*/
unsigned liesbit(void) {
    char c;
    unsigned i = 0;
    while(scanf("%c", &c) != EOF) {
        if (c == '0') {
            i = (i << 1);
        } else if (c == '1') {
            i = (i << 1) | 1;
        }
    }
    return i;
}

int main(void) {
    unsigned i1, i2;
    printf("Please type your first number:\n");
    i1 = liesbit();
    printf("Please type your second number:\n");
    i2 = liesbit();
    printf("a & b = ");
    schreibbit(i1 & i2);
    printf("a | b = ");
    schreibbit(i1 | i2);
    printf("a ^ b = ");
    schreibbit(i1 ^ i2);
    return 0;
}
