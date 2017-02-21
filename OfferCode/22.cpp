/*
题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
        if(root == NULL) return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* front = que.front();
            que.pop();
            result.push_back(front->val);
            if(front->left) que.push(front->left);
            if(front->right) que.push(front->right);
        }
        return result;
    }
};