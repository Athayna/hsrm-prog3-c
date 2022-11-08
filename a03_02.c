#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char code[] = {'w', 'g', 's', 'n', 'q', 'c', 'd', 'v', 'm', 'e', 'y', 'l', 'u', 'z', 'o', 'a', 'b', 'h', 'r', 'j', 'f', 'k', 'x', 'i', 'p', 't'};
    int i, move[26];
    char c;

    for(i = 0; i < 26; i++) {
        move[i] = code[i] - alphabet[i];
    }

    printf("Please enter a message:\n");
    if (argc == 0) {
        printf("Please try again and type encrypt or decrypt.");
    } else if (!strcmp(argv[1], "encrypt")) {
        while(scanf("%c", &c) != EOF) {
            if(c >= 'a' && c <= 'z') {
                printf("%c", (c + move[c - 'a']));
            } else {
                printf("%c", c);
            }
        }
    } else if (!strcmp(argv[1], "decrypt")) {
        while(scanf("%c", &c) != EOF) {
            if(c >= 'a' && c <= 'z') {
                printf("%c", (c - move[c - 'a']));
            } else {
                printf("%c", c);
            }
        }
    }

    return 0;
}