

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // join arrays
    int *joined;
    int i=0, j=0, avgIdx=(nums1Size+nums2Size)/2;
    double retval;
    joined = (int*) malloc( sizeof(int) * (nums1Size+nums2Size) );
    printf("sizes %d %d\n", nums1Size, nums2Size);
    
    
    if(nums1Size!=0 && nums2Size!=0) {
        while(1) {
            if(nums1[i]<nums2[j]) {
                printf("joined[%d]=%d\n",i+j,nums1[i]);
                joined[i+j] = nums1[i];
                i++;
                if(i>=nums1Size) {
                    while(j!=nums2Size) {
                        printf("joined[%d]=%d\n",i+j,nums2[j]);
                        joined[i+j] = nums2[j];
                        j++;
                    }
                    break;
                }
            }
            else {
                printf("joined[%d]=%d\n",i+j,nums2[j]);
                joined[i+j] = nums2[j];
                j++;
                if(j>=nums2Size) {
                    while(i!=nums1Size) {
                        joined[i+j] = nums1[i];
                        i++;
                    }
                    break;
                }
            }
        }
    }    
    else if(nums1Size==0) { 
        for(j=0; j<nums2Size; j++) {
            joined[j] = nums2[j];
        }
    }
    else if(nums2Size==0) { 
        for(i=0; i<nums1Size; i++) {
            joined[i] = nums1[i];
        }
    }
    
    
    if((nums1Size+nums2Size)%2) { // odd
        retval = (double) joined[avgIdx];
    }
    else {
        retval = (double) (joined[avgIdx] + joined[avgIdx-1])/2;
    }
    

    free(joined);
    // retval = middle on array (or avg of neighbors)
    return retval;
}