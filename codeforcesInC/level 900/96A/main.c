#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 96A
//printf("A\n");

int main(int argc, char** argv)
{
    int i, strLen;
    int inARow=1;
    char str[101];
    scanf("%s", str);

    strLen = strlen(str);
    if (strlen>=7) {
        for(i=1; i<strLen && inARow<7; i++) {
            if (str[i] == str[i-1]) {
                inARow++;
            }
            else {
                inARow=1;
            }
        }
    }

    if(inARow>=7) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
