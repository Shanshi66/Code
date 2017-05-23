/*
题目：请实现两个函数，分别用来序列化和反序列化二叉树
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
    char* Serialize(TreeNode *root) {
        string serial;
        dfs(serial, root);
        if(serial.length() > 0) serial.pop_back();
        return const_cast<char *>(serial.c_str());
    }
    
    void dfs(string &serial, TreeNode *root){
        if(root == NULL) {
            serial += "$ ";
            return;
        }
        serial += toString(root->val);
        serial += ' ';
        dfs(serial, root->left);
        dfs(serial, root->right);
    }
    
    string toString(int val){
        stringstream tmp;
        tmp << val;
        return tmp.str();
    }
    
    int toInt(string s){
        stringstream tmp(s);
        int ans;
        tmp >> ans;
        return ans;
    }
    
    TreeNode* Deserialize(char *str) {
        if(strlen(str) == 1) return NULL;
    	
        TreeNode* root = new TreeNode(0);
        string serial(str);
        stringstream serialStream(serial);
        string tmp;
        serialStream >> tmp;
        root->val = toInt(tmp);
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            if(s.top()->left != NULL && s.top()->right != NULL) {
                s.pop();
                continue;
            }
        	serialStream >> tmp;
            if(tmp == "$") {
                serialStream >> tmp;
                if(tmp == "$") {
                    s.pop();
                }
                else {
                    TreeNode* right = new TreeNode(toInt(tmp));
                    s.top()->right = right;
                    s.push(right);
                }
            } else if(s.top()->left == NULL){
                TreeNode* left = new TreeNode(toInt(tmp));
                s.top()->left = left;
                s.push(left);
            } else {
                TreeNode* right = new TreeNode(toInt(tmp));
                s.top()->right = right;
                s.push(right);
            }
        }
        return root;
    }
};