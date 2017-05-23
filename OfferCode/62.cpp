/*
题目：给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
       	return theKthNode(pRoot, k);
    }
    TreeNode* theKthNode(TreeNode* pRoot, int &k){
        if(k <= 0) return NULL;
        if(pRoot == NULL) return NULL;
        TreeNode* node = NULL;
        node = theKthNode(pRoot->left, k);
        if(node != NULL) return node;
        if((--k) == 0) return pRoot;
        node = theKthNode(pRoot->right, k);
    	return node;
    }
};