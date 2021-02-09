/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define QUEUE_SIZE 10000

bool isCousins(struct TreeNode* root, int x, int y){
    int l = 0, r = 0;
    struct TreeNode* q[QUEUE_SIZE];
    struct TreeNode *parent;
    parent = root;
    int found = 0, widthLeft = 1, nextWidth = 0;
    
    
    
    while(widthLeft>0) {
        if(parent->left && parent->right && (parent->left->val == x || parent->left->val == y) && (parent->right->val == x || parent->right->val == y) ) {
            break; // bro and sis
        }
        
        if(parent->val == x || parent->val == y) {
            found++;
        }
        
        if(parent->left) {
            nextWidth++;
            q[r++] = parent->left;
        }
        if(parent->right) {
            nextWidth++;
            q[r++] = parent->right;
        }

        parent = q[l++];
        if (--widthLeft == 0) {
            if(found) {
                break;
            }
            widthLeft = nextWidth;
            nextWidth = 0;
        }
    
    }
    
    
    
    if(found == 0 || found == 1) {
        printf("1found: %d\n", found);
        return 0;
    } else if(found == 2) {
        printf("2found: %d\n", found);
        return 1;
    } else {
        printf("3found: %d\n", found);
        return 0;
    }
}