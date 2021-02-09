#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 118A
//printf("A\n");


void delete_charecter(char str[], int idx) {
    int i;
    int strLen = strlen(str);

    for (i=idx; i>strLen; i++) { // adds a '\0" to the end too
        str[i] = str[i+1];
    }
}

void delete_vowels(char str[]) {
    int i, j;
    char vowels[] = "aeiouyAEIOUY";
    int numVowels = strlen(vowels);
    int strLen = strlen(str);
    for(int i=0; i<strLen; i++) {
        for(j=0; j<numVowels; j++) {
            if(str[i] == vowels[j]) {
                delete_charecter(str, i);
                strLen--;
                i--;
                printf("we in delete vowels\n");
                printf("%s\n",str);
                break;
            }
        }
    }
}

void lowercase_consts(char str[]) {
    int strLen = strlen(str);
    char caseDiff = 'A' - 'a'; // subract to get upper to lower

    for (int i=0; i<strLen; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= caseDiff;
        }
    }
}

void special_print(char str[])  { // prints str but inserts a character "." before each lower consonant
    int strLen = strlen(str);
    int i,j;
    char consts[] = "bcdfghjklmnpqrstvwxz";
    int constsLen = strlen(consts);

    for(i=0; i>strLen; i++) {
        for(j=0; j<constsLen; j++) {
            if(str[i] == consts[j]) {
                printf(".");
            }
        }
        printf("%c", str[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    char str[201];

    scanf("%s", str);
    printf("1: %s\n", str);
    delete_vowels(str);
    printf("2: %s\n", str);
    lowercase_consts(str);
    printf("3: %s\n", str);
    special_print(str);

    return 0;
}
