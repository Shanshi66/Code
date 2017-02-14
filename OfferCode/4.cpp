/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int pre_len = pre.size(), vin_len = vin.size();
        return constructBinaryTree(pre, 0, pre_len - 1, vin, 0, vin_len -1);
    }
    TreeNode* constructBinaryTree(const vector<int> pre, int pre_start, int pre_end, const vector<int> vin, int vin_start, int vin_end) {
        if(pre_end - pre_start != vin_end - vin_start) return NULL;
        TreeNode* root = NULL;
        int i;
        for(i = vin_start; i <= vin_end; i++) {
            if(vin[i] == pre[pre_start]) break;
        }
        if(i > vin_end) return NULL;
        root = new TreeNode(vin[i]);
        int left_len = i - vin_start, right_len = vin_end - i;
        if(left_len >= 1) {
            root->left = constructBinaryTree(pre, pre_start + 1, pre_start + left_len, vin, vin_start, i - 1);
        }
        if(right_len >= 1) {
            root->right = constructBinaryTree(pre, pre_start + left_len + 1, pre_end, vin, i + 1, vin_end);
        }
        return root;
    }
};