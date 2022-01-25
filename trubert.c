#include <stdio.h>

int main(void) {
    int zahl, rest, anzahl, i;

    printf("Please enter a positive number:\n");
    scanf("%d", &zahl);

    if(zahl >= 100) {
        rest = zahl % 100;
        anzahl = zahl / 100;
        for(i = 0; i < anzahl; i++) {
            printf("C");
        }
        zahl = rest;
    }
    if(zahl >= 50) {
        rest = zahl % 50;
        anzahl = zahl / 50;
        for(i = 0; i < anzahl; i++) {
            printf("L");
        }
        zahl = rest;
    }
    if(zahl >= 10) {
        rest = zahl % 10;
        anzahl = zahl / 10;
        for(i = 0; i < anzahl; i++) {
            printf("X");
        }
        zahl = rest;
    }
    if(zahl >= 5) {
        rest = zahl % 5;
        anzahl = zahl / 5;
        for(i = 0; i < anzahl; i++) {
            printf("V");
        }
        zahl = rest;
    }
    if(zahl >= 1) {
        rest = zahl % 1;
        anzahl = zahl / 1;
        for(i = 0; i < anzahl; i++) {
            printf("I");
        }
        zahl = rest;
    }

    return 0;
}