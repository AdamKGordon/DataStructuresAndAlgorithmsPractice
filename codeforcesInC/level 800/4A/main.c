#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 4A

void answer(int num) {
    //printf("%d\n", num);
    if (num>=4 && !(num%2)) {
        printf("YES");
    }
    else if ( !(num>=6 && !(num%2)) ) {
        printf("NO");
    }
    else {
        printf("%d\n", num);
    }
}

int main(int argc, char** argv)
{
    int num;
    // int num = atoi(argv[argc-1]);
    char str1[20]; scanf("%s", str1);

    answer(atoi(str1));

    return 0;
}