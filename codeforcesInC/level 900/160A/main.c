#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 160A
//printf("A\n");

int comparator(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b);
}

int main(int argc, char** argv) {
    int i;
    int numCoins;
    int my_tot=0;
    int tot=0;
    float half_tot;
    scanf("%d",&numCoins);
    int coinVals[numCoins];

    for (i=0; i<numCoins; i++) {
        scanf("%d", &coinVals[i]);
        tot += coinVals[i];
    }
    half_tot=tot/2;
    qsort(coinVals,numCoins,sizeof(int),comparator);

    for (i=numCoins-1; i>=0; i--) {
        my_tot += coinVals[i];
        if (my_tot>half_tot) {
            break;
        }
    }

    printf("%d\n", numCoins-i);
    //printf("%d %f %d\n", my_tot, half_tot, tot);

    return 0;
}
