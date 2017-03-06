/*
题目：输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
		if(pRoot == NULL) return 0;
        return dfs(pRoot);
    }
    int dfs(TreeNode* root){
        if(root->left == NULL && root->right == NULL) return 1;
        int depth = -1;
        if(root->left != NULL) depth = max(depth, 1 + dfs(root->left));
        if(root->right != NULL) depth = max(depth, 1 + dfs(root->right));
        return depth;
    }
};