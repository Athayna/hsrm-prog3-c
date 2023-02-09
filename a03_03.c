#include <stdio.h>
#include <ctype.h>

void soundex(const char s[], char res[]) {
    int j, k, reslen = 1, i = 1;
    char *key[] = {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};
    /*char key[][9] = {{"BFPV"}, {"CGJKQSXZ"}, {"DT"}, {"L"}, {"MN"}, {"R"}};*/
    res[0] = toupper(s[0]);

    while(s[i]) {
        for(j = 0; j < 6; j++) {
            for(k = 0; key[j][k]; k++) {
                if (toupper(s[i]) == key[j][k]) {
                    res[reslen] = (j + 1) + '0';
                    reslen++;
                    i++;
                    break;
                }
            }
        }
        
        if(reslen == 6) {
            break;
        }
        i++;
    }

    if(reslen < 6) {
        while(reslen < 7) {
            res[reslen] = '0';
            reslen++;
        }
    }

    res[7] = 0;
}

int main(void) {
    // broken
    char s[100];
    char res[7];

    while(scanf("%s", s) != EOF) {
        printf("Enter a word:\n");
        soundex(s, res);
        printf("%s\n", res);
    }

    return 0;
}