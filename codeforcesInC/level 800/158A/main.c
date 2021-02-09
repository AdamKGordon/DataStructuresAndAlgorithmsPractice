#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 158A


int main(int argc, char** argv)
{
    int n, k, tmp;
    int i=0;
    int j=0;
    int num_advancing=0;
    int nums[50];

    //scanf("%d%d", &n, &k);
    scanf("%d", &n);scanf("%d", &k);


    for(i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    for(j=0; j<n; j++) {
        if(nums[j]>0 && nums[j]>=nums[k-1]) {
            num_advancing++;
        }
        else {
            break;
        }
    }

    printf("%d\n", num_advancing);

    return 0;
}
