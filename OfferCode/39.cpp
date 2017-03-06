/*
题目：输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/


class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot == NULL) return true;
        if(IsBalanced_Solution(pRoot->left) == false) return false;
        if(IsBalanced_Solution(pRoot->right) == false) return false;
        int leftDepth = treeDepth(pRoot->left);
        int rightDepth = treeDepth(pRoot->right);
        if(abs(leftDepth - rightDepth) > 1) return false;
        return true;
    }
    
    int treeDepth(TreeNode* root) {
   		if(root == NULL) return 0;
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};


/*
效率优化
*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth;
        if(isBalanced(pRoot, depth)) return true;
        return false;
    }
    
    bool isBalanced(TreeNode* root, int &depth){
        if(root == NULL) {
            depth = 0;
            return true;
        }
        int left, right;
        if(isBalanced(root->left, left) == false) return false;
        if(isBalanced(root->right, right) == false) return false;
        if(abs(left - right) > 1) return false;
        depth = max(left, right) + 1;
        return true;
    }
};