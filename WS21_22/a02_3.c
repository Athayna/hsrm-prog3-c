#include <stdio.h>

int main(void) {
    int v[20];

    scanf("%d", &v) != EOF;

    int i, j, min, trade1, trade2;

    for(i = 0; i < (sizeof(v) / sizeof(v[0])); i++) {
        min = v[i];
        trade1 = v[i];
        trade2 = i;
        
        for(j = i; j < (sizeof(v) / sizeof(v[0])); j++) {
            if(v[j] < min) {
                min = v[j];
                trade2 = j;
            }
        }

        v[i] = min;
        v[trade2] = trade1;
    }

    for(i = 0; i < (sizeof(v) / sizeof(v[0])); i++) {
        printf("\n%6d", v[i]);
    }

    return 0;
}