#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 133A
//printf("A\n");



int main(int argc, char** argv) {

    char str[101];
    int i;
    int printYes =0 ;

    scanf("%s", str);
    int strLen = strlen(str);

    for(i=0;i<strLen;i++) {
        if(str[i]=='H' || str[i]=='Q' || str[i]=='9') {
            printYes=1;
        }
    }

    if (printYes) {
        printf("YES");
    }

    else {
        printf("NO");
    }

    return 0;
}
