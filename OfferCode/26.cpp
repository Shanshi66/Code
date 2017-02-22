/*
题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

注意：
1. 二级指针被赋值的时候一定要用*取值
2. 凡是涉及要引用指针里面的东西的时候一定要判断该指针是否为空
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
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL) return NULL;
        TreeNode* p_tail = NULL;
        return convert(pRootOfTree, &p_tail);
    }
    
    TreeNode* convert(TreeNode* root, TreeNode** p_tail){
		if(root->left == NULL && root->right == NULL) {
            *p_tail = root;
            return root;
        }
        TreeNode* p_left_head = NULL, *p_right_head = NULL;
        TreeNode* p_left_tail = NULL, *p_right_tail = NULL;
        
        if(root->left != NULL){
            p_left_head = convert(root->left, &p_left_tail);
        }
       	if(root->right != NULL){
            p_right_head = convert(root->right, &p_right_tail);
        }
        
        TreeNode* p_head = NULL;
        root->left = p_left_tail;
        root->right = p_right_head;
        
        if(p_left_tail != NULL) {
            p_left_tail->right = root;
            p_head = p_left_head;
        } else {
           	p_head = root;
        }
        
        if(p_right_head != NULL) {
            p_right_head->left = root;
            *p_tail = p_right_tail;
        } else {
            *p_tail = root;
        }
        
        return p_head;
    }
};