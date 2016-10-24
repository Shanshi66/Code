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
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        dfs(ans, root, sum);
        return ans;
    }
    void dfs(int &ans, TreeNode* root, int sum){
        if(root == NULL) return;
        pathsExist(ans, root, sum);
        dfs(ans, root->left, sum);
        dfs(ans, root->right, sum); 
    }
    void pathsExist(int &ans, TreeNode* root, int sum){
        if(sum - root->val == 0){
            ans++;
        }
        if(root->left != NULL) pathsExist(ans, root->left, sum - root->val);
        if(root->right != NULL) pathsExist(ans, root->right, sum - root->val);
    }
};