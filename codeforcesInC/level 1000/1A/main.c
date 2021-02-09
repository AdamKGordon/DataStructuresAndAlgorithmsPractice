#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1A
//printf("A\n");



int main(int argc, char** argv) {

    long long int numStones;
    long int n,m,a; // width, height, flagstone size
    long int stonesWide, stonesHeight;

    scanf("%ld%ld%ld", &n, &m, &a);

    stonesWide  = n/a;
    stonesHeight = m/a;

    if (n%a) {
        stonesWide++;
    }
    if (m%a) {
        stonesHeight++;
    }
    numStones = stonesHeight*stonesWide;
    printf("%I64d\n",numStones);
    printf("%ld\n",stonesHeight);
    printf("%ld\n",stonesWide);

    return 0;
}
