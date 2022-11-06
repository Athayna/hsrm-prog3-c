#include <stdio.h>

int main(void) {
    unsigned char c;
    printf("This program encodes text with the ROT13 encoder.\n");
    printf("Please enter a text:\n");
    scanf("%c", &c);
    while (c != EOF) {
        if (c > 'A' && c < 'Z') {
            c += 13;
            if (c > 'Z') {c -= 26;}
        } else if (c > 'a' && c < 'z') {
            c += 13;
            if (c > 'z') {c -= 26;}
        }
        printf("%c", c);
        scanf("%c", &c);
    }
    return 0;
}