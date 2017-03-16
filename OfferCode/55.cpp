/*
题目：一个链表中包含环，请找出该链表的环的入口结点。
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

//我的思路：用set保存节点，遍历到第一个在set中的元素就是入口节点
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		set<ListNode*> visit;
        ListNode* p = pHead;
        while(p != NULL && visit.find(p) == visit.end()) {
            visit.insert(p);
            p = p->next;
        }
        return p;
    }
};

// 剑指offer思路
// 先求出环的长度：用一快一慢指针，俩指针相遇后标记下当前点，再从当前点开始遍历，同时计数，再次回到当前点时，即可求出环的长度K
//然后，还是用俩指针，一个指针先走K步，然后俩指针同时走，相遇节点即是入口节点
//
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		ListNode* p1 = pHead, *p2 = pHead;
        while(p1 != NULL && p2 != NULL){
            p1 = p1->next;
            p2 = p2->next;
            if(p2 != NULL) p2 = p2->next;
            else break;
            if(p1 == p2) break;
        }
        if(p1 == NULL || p2 == NULL) return NULL;
        ListNode* mark = p1;
        int count = 1;
        p2 = p2->next;
        while(p1 != p2){
            count++;
            p2 = p2->next;
        }
        p1 = p2 = pHead;
        while(count--){
            p2 = p2->next;
        }
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};


