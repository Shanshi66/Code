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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* f = que.front();
            que.pop();
            swap(f->left, f->right);
            if(f->left != NULL) que.push(f->left);
            if(f->right != NULL) que.push(f->right);
        }
        return root;
    }
};