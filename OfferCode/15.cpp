/*
题目：输入一个链表，反转链表后，输出链表的所有元素。

思路：保留当前节点的前一个和后一个指针。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == NULL) return NULL;
        if(pHead->next == NULL) return pHead;
        ListNode* pre = NULL;
        ListNode* p_ahead = pHead, *p_behind = pHead->next;
        while(p_ahead->next != NULL) {
            p_ahead->next = pre;
            pre = p_ahead;
            p_ahead = p_behind;
            p_behind = p_behind->next;
        }
        p_ahead->next = pre;
        return p_ahead;
    }
};