/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode *newNode(int val) {
    struct TreeNode *node;
    node = (struct  TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* childNodeRecr(int l, int r, int *nums) {
    struct TreeNode *newN;
    int mid  = l + (r-l)/2;
    printf("%d %d %d\n",l,mid,r);
    newN = NULL;

    if(l<=r) {
        newN = newNode(nums[mid]);
        if(l<r){
            newN->left  = childNodeRecr(l,  mid-1, nums); // l
            newN->right = childNodeRecr(mid+1,  r, nums); // r
        }
    }
    
    return newN;
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode *head;
        
    head = childNodeRecr(0, numsSize-1, nums);
    
    return head;
}