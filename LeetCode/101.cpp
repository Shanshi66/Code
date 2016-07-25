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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(isSymmetric(root, root)) return true;
        else return false;
    }
    bool isSymmetric(TreeNode *root1, TreeNode *root2){
        if(root1->val != root2->val) return false;
        if(((root1->left != NULL) ^ (root2->right != NULL)) ||
           ((root1->right != NULL) ^ (root2->left != NULL))) return false;
        if(root1->left != NULL){
            if(!isSymmetric(root1->left, root2->right)) return false;
        }
        if(root1->right != NULL){
            if(!isSymmetric(root1->right, root2->left)) return false;
        }
        return true;
    }
};