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
    unsigned i = 0, num = 0;
    char string[17];
    scanf("%s", string);

    while(string[i] != '\0') {
        if (string[i] == '0') {
            num = (num << 1);
        } else if (string[i] == '1') {
            num = (num << 1) | 1;
        }
        i++;
    }
    return num;
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
