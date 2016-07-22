/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> que;
        int depth = 0;
        if(root == NULL) return depth;
        root->val = 1;
        que.push(root);
        while(!que.empty()){
            TreeNode *f  = que.front();
            que.pop();
            if(f->left != NULL){
                f->left->val = f->val + 1;
                que.push(f->left);
            }else {
                depth = max(depth, f->val);
            }
            if(f->right != NULL){
                f->right->val = f->val + 1;
                que.push(f->right);
            }else {
                depth = max(depth, f->val);
            }
        }
        return depth;
    }
};