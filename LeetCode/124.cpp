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
    int maxPathSum(TreeNode* root) {
        int ans = -0x3fffffff;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int left = dfs(root->left, ans) + root->val;
        int right = dfs(root->right, ans) + root->val;
        ans = max(ans, left + right - root->val);
        return max(left, right);
    }
};