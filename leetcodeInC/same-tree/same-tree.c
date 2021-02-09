/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfsCheck(struct TreeNode* p, struct TreeNode* q) {
    printf("_____\n");

    bool sameTree = 1;
    if(!p&&!q) {
        return 1;
    }
    
    if(!sameTree || (!p||!q)&&(p!=q) || p->val != q->val) {
        printf("ahere\n");
        return 0;
    }
    if(sameTree && p->left != NULL || q->left != NULL) {
        if(p->left != NULL && q->left != NULL) {
                    printf("aa\n");
            sameTree = dfsCheck(p->left, q->left);
        } else {
        printf("bhere\n");
            return 0;
        }
    }
    if (sameTree && (p->right != NULL || q->right != NULL)) {
        if (p->right != NULL && q->right != NULL) {
                    printf("bb\n");
            sameTree = dfsCheck(p->right, q->right);
        } else {
        printf("vhere\n");
            return 0;
        }
    }
            printf("zhere %d\n", sameTree);

    return sameTree;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    return dfsCheck(p,q);
}