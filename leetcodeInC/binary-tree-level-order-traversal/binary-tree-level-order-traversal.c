/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int intPow(int base, int pow) {
    int ret = 1;
    int i;
    for(i=0; i<pow; i++) {
        ret *= base;
    }
    return ret;
}
#define QUEUE_SIZE 900 // inc this if width gets too big (too many nodes in q)
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root) {
        int **stupid;
        stupid = (int **) malloc(sizeof(int*));
        *returnSize = 0;
        
        return stupid;
    }    
    
    int **ret;
    int *tmp;
    int retColSizes[800] = {0}; // inc size if depth too much
    //printf("%d asd\n", retColSizes[3]);
    retColSizes[0] = 1;
    tmp = (int *) malloc(sizeof(int));
    tmp[0] = root->val;
    //    ret = (int **) malloc(sizeof(int *) * (*returnSize));
    ret = (int **) malloc(sizeof(int *) * QUEUE_SIZE);
    int nextWidth = 0, widthLeft = 1;
    //int q[intPow(2, *returnSize)];
    struct TreeNode *q[QUEUE_SIZE];
    int depth = 1;
    int i=0,j=0;
    int l = 0, r = 0;
    struct TreeNode *parent;
    parent = root;
        
    while(!(widthLeft <= 0 && nextWidth <= 0)) {
        //printf("a\n");

        //printf("_\n");
        //printf("%d\n",parent->val);
        //printf("_\n");

        tmp[i++] = parent->val;
        if(parent->left != NULL) {
            //printf("%d add left %d\n",r,  parent->left->val);
            nextWidth++;
            q[r++ % QUEUE_SIZE] = parent->left;
        }
        if(parent->right != NULL) {
            //printf("%d add right %d\n", r, parent->right->val);
            nextWidth++;
            q[r++ % QUEUE_SIZE] = parent->right;
        }
        //if(q[l] == NULL){
        //    printf("wtf\n");
        //}
        parent = q[l++ % QUEUE_SIZE];
        widthLeft--;
        if(widthLeft == 0) {
            ret[depth-1] = tmp;
            if(nextWidth) {
                retColSizes[depth++] = nextWidth;
                tmp = (int *) malloc(sizeof(int) * nextWidth);
            }
            //printf("b\n");
           // printf("c\n");
            i = 0;
            widthLeft = nextWidth;
            nextWidth = 0;
        }
        //printf("end %d %d\n", widthLeft, nextWidth);       
    }
    
    *returnSize = depth;
    int *retSizes;
    //printf("g\n");
    retSizes = (int *) malloc(sizeof(int) * (depth));
    //printf("h\n");
    for(i=0; i < depth; i++) {
        //printf("j %d %d\n", i, retColSizes[i]);
        retSizes[i] = retColSizes[i];
        //printf("j %d %d\n", i, retColSizes[i]);
    }
    //printf("k\n");
    *returnColumnSizes = retSizes;
    //printf("m %d\n", *returnSize);

    /*
    for (i = 0; i < depth; i++) {
        for (j = 0; j < (*returnColumnSizes)[i]; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    */
    return ret;
}