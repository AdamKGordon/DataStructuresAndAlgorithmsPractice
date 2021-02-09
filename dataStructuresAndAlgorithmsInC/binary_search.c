#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//printf("A\n");

//



void main()
{
    int sl[] = {1, 2, 3, 6,6,6,7, 9, 10,11,44,55,66,77,88,99,100,200,300,400,500,600,700,800,900, 999};

    int l,r,mid;
    l=0;
    r=sizeof(sl)/sizeof(sl[0]);

    int target = 999;
    int idx=-1;

    while(r-l>0) {
        mid = l + (r-l)/2;
        if(sl[mid]==target) {
            idx = mid;
            break;
        }
        else if (sl[mid] > target) {
            r = mid;
        }
        else if (sl[mid] < target) {
            l = mid;
        }
    }

    if(idx==-1) {
        printf("NA\n");

    }
    else{
        printf("idx=%d,     sl[%d]=%d\n", idx,idx,sl[idx]);
    }
}