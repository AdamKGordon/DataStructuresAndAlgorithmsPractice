#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 405A
//printf("A\n");



int main(int argc, char** argv) {
    int n; // num cols
    int cubesPerRow[100]={0};
    int i, j;
    int maxHeight=0;

    scanf("%d", &n);
    int retHeights[n];
    int colHeights[n];

    for (i=0; i<n; i++) {
        retHeights[i] = 0;
        scanf("%d", &colHeights[i]);
        if (colHeights[i] > maxHeight) {
            maxHeight = colHeights[i];
        }
        for (j=colHeights[i]-1; j>=0; j--) {
            cubesPerRow[j]++;
        }
    }

    for (j=0; j<maxHeight; j++) {
        for (i=cubesPerRow[j]; i>=0; i--) {
            retHeights[n-i]++;
        }
    }

    //print
    for(i=0; i<n; i++) {
        printf("%d ", retHeights[i]);
    }
    printf("\n");


    return 0;
}
