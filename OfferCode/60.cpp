/*
题目：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
    	vector<vector<int> > result;
        if(pRoot == NULL) return result;
        vector<TreeNode*> preLevel;
        preLevel.push_back(pRoot);
        result.push_back(vector<int>(1, pRoot->val));
        while(!preLevel.empty()){
            vector<TreeNode*> curLevel;
            vector<int> level;
            for(int i = 0; i < preLevel.size(); i++) {
                if(preLevel[i]->left != NULL) {
                    curLevel.push_back(preLevel[i]->left);
                	level.push_back(preLevel[i]->left->val);
                }
            	if(preLevel[i]->right != NULL) {
                    curLevel.push_back(preLevel[i]->right);
                    level.push_back(preLevel[i]->right->val);
                }
            }
            if(level.size() > 0) result.push_back(level);
            preLevel.swap(curLevel);
        }
        return result;
    }
    
};