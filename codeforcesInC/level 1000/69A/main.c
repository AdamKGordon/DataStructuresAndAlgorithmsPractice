#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 69A
//printf("A\n");


int main(int argc, char** argv) {
    int sumVector[3] = {0,0,0};
    int tmpVector[3];
    int numVectors,i;

    scanf("%d", &numVectors);

    for (i=0; i<numVectors; i++) {
        scanf("%d%d%d", &tmpVector[0],&tmpVector[1],&tmpVector[2]);
        sumVector[0] += tmpVector[0];
        sumVector[1] += tmpVector[1];
        sumVector[2] += tmpVector[2];
    }

    if(sumVector[0] || sumVector[1] || sumVector[2]) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
    }

    return 0;
}
