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


//解法一，哈希
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

//解法二：因为链表末尾部分一定相同，可以让长的链表先走一部分，等长后在同时走，第一个相同的节点就是答案

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
    int getListLength(ListNode* phead){
        int len = 0;
        while(phead != NULL) {
            len++;
            phead = phead->next;
        }
        return len;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = getListLength(pHead1);
        int len2 = getListLength(pHead2);
        ListNode* p1 = NULL, *p2 = NULL;
        if(len1 > len2) {
            p1 = pHead1;
            p2 = pHead2;
        } else {
            p1 = pHead2;
            p2 = pHead1;
        }
        int k = abs(len1 - len2);
		while(k--){
            p1 = p1->next;
        }
        while(p1 != NULL && p2 != NULL) {
            if(p1 == p2) break;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};