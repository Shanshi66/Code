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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL){
            root->val = 1;
            return true;
        }
        else if(root->left == NULL){
            if(root->right->left == NULL && root->right->right == NULL){
                root->val = 2;
                return true;
            }
        }
        else if(root->right == NULL){
            if(root->left->right == NULL && root->left->left == NULL){
                root->val = 2;
                return true;
            }
        }
        else {
            if(isBalanced(root->left) && isBalanced(root->right)){
                root->val = max(root->left->val, root->right->val) + 1;
                if(abs(root->left->val - root->right->val) < 2)return true;
            }
        }
        return false;
    }
};