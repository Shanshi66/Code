/*
题目：在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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

// recursive 写法
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        if(pHead->next == NULL) return pHead;
        if(pHead->val != pHead->next->val) {
            ListNode* node = deleteDuplication(pHead->next);
            pHead->next = node;
        } else {
            ListNode* p = pHead;
            while(p->next != NULL && p->val == p->next->val) {
                p = p->next;
            }
            p = p->next;
            ListNode* q = pHead;
            while(q != p) {
                q = q->next;
                delete pHead;
                pHead = q;
            }
            pHead = deleteDuplication(p);
        }
        return pHead;
    }
};

