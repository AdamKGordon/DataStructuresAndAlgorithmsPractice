/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_DEPTH 20
void dfsAdd(struct TreeNode* head, int depth, int *rightView) {
    if(!head) {
        return 0;
    }
    if(!rightView[depth]) {
        rightView[depth] = head->val;
    }
    
    dfsAdd(head->right, depth+1, rightView);
    dfsAdd(head->left,  depth+1, rightView);

}

int* rightSideView(struct TreeNode* root, int* returnSize){
    int i;
    *returnSize = 0;
    int rightView[MAX_DEPTH] = {0};
    
    dfsAdd(root, 0, rightView);
    
    for (i = 0; rightView[i]; i++) {
        continue;
    }
    *returnSize = i;
    int *ret;
    ret = (int *) malloc(sizeof(int)*(*returnSize));
    for (i = 0; i<(*returnSize); i++) {
        ret[i] = rightView[i];
    }
    return ret;
}