#include <stdio.h>
#include <string.h>

char* encrypt(char *input, char *alphabet, char *code) {
    char message[40];
    char *pmessage;
    pmessage = &message[0];
    int i, j;

    for(i = 0, i < strlen(*input); i++) {
        for(j = 0; j < sizeof(*alphabet); i++) {
            if(alphabet[j] == input[i])
                message[i] = code[j];
        }
    }

    message[++i] = '\0';

    return pmessage; 
}

int main(void) {
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char code[] = {'w', 'g', 's', 'n', 'q', 'c', 'd', 'v', 'm', 'e', 'y', 'l', 'u', 'z', 'o', 'a', 'b', 'h', 'r', 'j', 'f', 'k', 'x', 'i', 'p', 't'};
    char input[40];
    int i = 0;

    while(scanf("%c", input[i++]) != EOF);

    printf("%s", encrypt(&input[0], &alphabet[0], &code[0]));

    return 0;
}