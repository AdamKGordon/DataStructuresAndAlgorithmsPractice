#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 231A


int main(int argc, char** argv)
{
    int i;
    int lines;
    char str[10];
    int total=0;

    scanf("%d", &lines);
    for(i=0; i<lines; i++) {
        scanf("%s", str);
        if ( (str[0]&&str[2])||(str[0]&&str[4])||(str[2]&&str[4]) ) {
            total++;
        }
    }
    if("0"){printf("aiosdjfios");}
    printf("%d", total);


    return 0;
}