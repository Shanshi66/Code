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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        vector<TreeNode*> ans = buildTree(1, n);
        return ans;
    }
    vector<TreeNode*> buildTree(int l, int r){
        vector<TreeNode*> trees;
        if(l > r) return trees;
        if(l == r){
            trees.push_back(new TreeNode(l));
            return trees;
        }
        for(int i = l; i <= r; i++){
            vector<TreeNode*> left = buildTree(l, i - 1);
            vector<TreeNode*> right = buildTree(i + 1, r);
            vector<TreeNode*> root_trees = combine(i, left, right);
            trees.insert(trees.end(), root_trees.begin(), root_trees.end());
        }
        return trees;
    }
    vector<TreeNode*> combine(int root_val, vector<TreeNode*> left, vector<TreeNode*> right){
        vector<TreeNode*> trees;
        if(left.size() == 0){
            for(auto child_root: right) {
                TreeNode* root = new TreeNode(root_val);
                root->left = NULL;
                root->right = child_root;
                trees.push_back(root);
            }
        } else if(right.size() == 0){
            for(auto child_root: left) {
                TreeNode* root = new TreeNode(root_val);
                root->right = NULL;
                root->left = child_root;
                trees.push_back(root);
            }
        } else {
            for(auto left_root: left){
                for(auto right_root: right){
                    TreeNode* root = new TreeNode(root_val);
                    root->left = left_root;
                    root->right = right_root;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};