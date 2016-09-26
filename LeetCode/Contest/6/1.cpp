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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        // if(root->left == NULL && root->right == NULL){
        //     return root->val;
        // }
        int sum = 0;
        if(root->left != NULL){
            sum += dfs(root->left, 0);
        }
        if(root->right != NULL){
            sum += dfs(root->right, 1);
        }
        return sum;
    }
    int dfs(TreeNode* node, int child_flag){
        if(node->left == NULL && node->right == NULL){
            if(child_flag == 0) return node->val;
            else return 0;
        }
        int sum = 0;
        if(node->left != NULL){
            sum += dfs(node->left, 0);
        }
        if(node->right != NULL){
            sum += dfs(node->right, 1);
        }
        return sum;
    }
};