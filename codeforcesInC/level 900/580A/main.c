#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 580A
//printf("A\n");



int main(int argc, char** argv) {
    int i,j,n,cur_num,prev_num;
    int inARow=1;
    int inARowMax=1;

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d",&cur_num);
        if(i==0) {
            prev_num=cur_num;
            continue;
        }
        if(cur_num>=prev_num) {
            inARow++;
            if(inARow > inARowMax) {
                inARowMax = inARow;
            }
        }
        else {
            inARow=1;
        }
        prev_num=cur_num;
    }
    printf("%d\n", inARowMax);

    return 0;
}
