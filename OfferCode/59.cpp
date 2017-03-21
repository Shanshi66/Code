/*
题目：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};1
*/

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
    	vector< vector<int> > result;
        if(pRoot == NULL) return result;
        vector<TreeNode*> preLevel;
        preLevel.push_back(pRoot);
        result.push_back(vector<int>(1, pRoot->val));
        bool ordered = false;
        while(preLevel.empty() == false){
            vector<TreeNode*> curLevel;
            vector<int> level;
            for(int i = 0; i < preLevel.size(); i++) {
                if(preLevel[i]->left != NULL) curLevel.push_back(preLevel[i]->left);
                if(preLevel[i]->right != NULL) curLevel.push_back(preLevel[i]->right);
            }
            if(ordered) {
                for(int i = 0; i < curLevel.size(); i++) {
                   level.push_back(curLevel[i]->val);
                }
            } else {
                for(int i = curLevel.size() - 1; i >= 0; i--) {
                   level.push_back(curLevel[i]->val);
                }
            }
            if(level.empty() == false) result.push_back(level);
            ordered = !ordered;
            preLevel.swap(curLevel);
        }
        return result;
    }
};