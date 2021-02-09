/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfsDepth(struct TreeNode* r, int curDepth) {
    int maxDepth = curDepth;
    int tmpDepth;
    
    if(!r) {
        return curDepth;
    }
    curDepth++;
    tmpDepth = dfsDepth(r->left, curDepth);
    if(maxDepth < tmpDepth) {
        maxDepth = tmpDepth;
    }
    tmpDepth = dfsDepth(r->right, curDepth);
    if(maxDepth < tmpDepth) {
        maxDepth = tmpDepth;
    }
    
    return maxDepth;
}

int maxDepth(struct TreeNode* root){
    return dfsDepth(root, 0);
}