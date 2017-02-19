/*
题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

注意：指针问题循环里面千万别忘记移动指针。

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
    	ListNode* head = NULL;
        if(pHead1->val < pHead2->val) {
            head = pHead1;
        	pHead1 = pHead1->next;
        }
        else {
        	head = pHead2;
            pHead2 = pHead2->next;
        }
        ListNode *p1 = pHead1, *p2 = pHead2, *p = head;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1 != NULL) p->next = p1;
        if(p2 != NULL) p->next = p2;
        return head;
    }
};