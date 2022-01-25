#include <stdio.h>

int main() {
    unsigned char input;
    char invalid = '#';
    int rotation = 13;
    int alphabet = 26;

    printf("Geben Sie ein Wort zum übersetzten ein: ");

    while (scanf("%c", &input) != EOF)
    {
        /*Nur Buchstaben*/
        if (input > 64 && input < 91 || input > 96 && input < 123)
        {
            if (input > 64 && input < 91)
            {
                input += rotation;
                if (input > 90)
                {
                    input -= alphabet;
                }
            }
            else
            {
                input += rotation;
                if (input > 122)
                {
                    input -= alphabet;
                }
            }
            printf("%c", input);
        }
        /*Für Sonderzeichen das ungültig Zeichen*/
        else
        {
            if (input != '\n')
                printf("%c", invalid);
        }
    }
    return 0;
}