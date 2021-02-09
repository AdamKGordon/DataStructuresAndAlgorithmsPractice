#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 282A
//printf("A\n");

int main(int argc, char** argv)
{
    int x,n,i;
    char str[4];

    scanf("%d", &n);

    x=0;
    for(i=0; i<n; i++) {
        scanf("%s", str);
        if(str[1] == '+') {
            x++;
        }
        else if (str[1] == '-') {
            x--;
        }
        else{
            printf("NOOOOOO!\n");
        }
    }
    printf("%d\n", x);

    return 0;
}