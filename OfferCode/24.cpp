/*
题目：输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

WA了多次的原因：
1. dfs时把NULL作为终止条件，会一条路径添加两遍，因为叶子节点左右孩子都是NULL

dfs的时候参数要想好
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector< vector<int> > res;
        if(root == NULL) return res;
        vector<int> path;
        dfs(res, root, expectNumber, path);
        return res;
    }

    void dfs(vector< vector<int> > &result, TreeNode* root, int number_left, vector<int> &path){
        path.push_back(root->val);
        number_left -= root->val;
        if(root->left == NULL && root->right == NULL) {
            if(number_left == 0) {
                vector<int> cur_path(path.begin(), path.end());
                result.push_back(cur_path);
            }
        }
        if(root->left != NULL){
            dfs(result, root->left, number_left, path);
        }
        if(root->right != NULL){
            dfs(result, root->right, number_left, path);
        }
        path.pop_back();
        number_left += root->val;
    }
};