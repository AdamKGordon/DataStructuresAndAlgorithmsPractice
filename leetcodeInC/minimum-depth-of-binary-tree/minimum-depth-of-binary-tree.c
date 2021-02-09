/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


#define QUEUE_SIZE 500

int minDepth(struct TreeNode* root){
    if (!root) {
        return 0;
    }
    
    int l = 0, r = 0;
    struct TreeNode *queue[QUEUE_SIZE];
    struct TreeNode *head;
    head = root;
    int width = 1, depth = 1, nextWidth=0;
    
    while(!(head->left == NULL && head->right == NULL)) {
        printf("hi\n");
        if(head->left != NULL) {
            queue[r % QUEUE_SIZE] = head->left;\
            r++;
        }
        if(head->right != NULL) {
            queue[r % QUEUE_SIZE] = head->right;
            r++;
        }
        head = queue[l % QUEUE_SIZE];
        l++;
        width--;
        if(width == 0) {
            width = r-l+1;
            depth++;
        }
    }

    return depth;
}