/*
输入两个链表，找出它们的第一个公共结点。

*/


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        set<ListNode*> s;
       	ListNode* p = pHead1;
        while(p != NULL) {
            s.insert(p);
            p = p->next;
        }
        p = pHead2;
        ListNode* res = NULL;
        while(p) {
            if(s.find(p) != s.end()) {
                res = p;
                break;
            }
            p = p->next;
        }
        return res;
    }
};