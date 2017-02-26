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
    int getMinimumDifference(TreeNode* root) {
        vector<int> seq;
        dfs(root, seq);
        int ans = INT_MAX;
        for(int i = 1; i < seq.size(); i++) {
            ans = min(ans, abs(seq[i] - seq[i - 1]));
        }
        return ans;
    }
    inline int abs(const int &x){
        if(x < 0) return -x;
        else return x;
    }
    void dfs(const TreeNode *root, vector<int> &seq){
        if(root->left == NULL && root->right == NULL){
            seq.push_back(root->val);
            return;
        }
        if(root->left != NULL) dfs(root->left, seq);
        seq.push_back(root->val);
        if(root->right != NULL) dfs(root->right, seq);
    } 
};