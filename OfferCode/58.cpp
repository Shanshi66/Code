/*
题目：请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的
*/


class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == NULL) return true;
        if(pRoot->left == NULL && pRoot->right == NULL) return true;
    	if(isSymmetrical(pRoot->left, pRoot->right)) return true;
        else return false;
    }
	
    bool isSymmetrical(TreeNode* root1, TreeNode* root2){
        if(root1->val != root2->val) return false;
        bool ans = true;
        if(root1->left != NULL && root2->right != NULL) {
            ans = ans && isSymmetrical(root1->left, root2->right);
        } else if(root1->left == NULL && root2->right == NULL) {
            ans = ans && true;
        } else {
            ans = ans && false;
        }
        if(!ans) return ans;
        if(root1->right != NULL && root2->left != NULL) {
            ans = ans && isSymmetrical(root1->right, root2->left);
        } else if(root1->right == NULL && root2->left == NULL) {
            ans = ans && true;
        } else {
            ans = ans && false;
        }
        return ans;
    }
};