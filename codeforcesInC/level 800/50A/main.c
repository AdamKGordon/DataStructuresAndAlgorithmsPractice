#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 50A
//printf("A\n");

int main(int argc, char** argv)
{
    int num_dom;
    int m,n;

    scanf("%d%d", &m, &n);
    if(m*n%2 == 0) { //even
        num_dom = m*n/2;
    }
    else {
        num_dom = (m*n-1)/2;
    }

    printf("%d\n", num_dom);
    return 0;
}
