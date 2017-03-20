/*
题目：给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

思路：如果有右子树，则下一个节点是右子树最左边的点；如果没有右子树，如果当前节点是父节点的左孩子，则下一个节点是父节点，否则一直向上找到一个节点属于其父节点的左孩子，则父节点是下一个节点。
*/


class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == NULL) return NULL;
        TreeLinkNode* ans = NULL;
        if(pNode->right != NULL) {
            TreeLinkNode *p = pNode->right;
            while(p->left != NULL){
                p = p->left;
            }
            ans = p;
        } else {
            if(pNode->next == NULL) {
                ans = NULL;
            }
            else if(pNode == pNode->next->left) ans = pNode->next;
            else {
                TreeLinkNode* p = pNode;
                while(p->next != NULL && p != p->next->left){
                    p = p->next;
                }
                ans = p->next;
            }
        }
        return ans;
    }
};