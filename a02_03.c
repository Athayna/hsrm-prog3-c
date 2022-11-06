#include <stdio.h>

int main(void) {
    int numbers[20];
    int arrLength, storage, j, i = 0;
    while((scanf("%d", &numbers[i]) != EOF) && (i <= 20)) {
        i++;
    }
    arrLength = i;
    for(i = 0; i < arrLength; i++) {
        for(j = i + 1; j < arrLength; j++) {
            if (numbers[j] < numbers[i]) {
                storage = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = storage;
            }
        }
        printf("%6d\n", numbers[i]);
    }
    return 0;
}