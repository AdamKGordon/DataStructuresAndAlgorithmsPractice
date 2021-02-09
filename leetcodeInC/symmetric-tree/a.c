/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfsCheck(struct TreeNode* l, struct TreeNode* r) {
    bool symetric = 1;
    
    if (!l && !r) {       // both NULL
        return 1;
    } else if(!l || !r) { // only one is NULL
        return 0;
    } else if(l->val != r->val) { //neither null so comp vals
        return 0;
    }

    symetric = dfsCheck(l->left, r->right);
    if(symetric) {
        symetric = dfsCheck(l->right, r->left);    
    }

    return symetric;
}

bool isSymmetric(struct TreeNode* root){
    return root ? dfsCheck(root->left, root->right) : 1; //ternary
}