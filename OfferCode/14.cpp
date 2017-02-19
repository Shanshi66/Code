/*
题目：输入一个链表，输出该链表中倒数第k个结点。

本题有三个陷阱：
1. pListHead可能为空
2. k可能大于链表长度
3. unsigned k可能为0， k - 1就是个很大的正数
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead == NULL || k == 0) return NULL;
        stack<ListNode*> values;
        ListNode* p_head = pListHead;
        while(p_head != NULL) {
            values.push(p_head);
            p_head = p_head->next;
        }
        if(values.size() < k) {
            return NULL;
        }
        while(k - 1 > 0) {
        	values.pop();
            k--;
        }
        return values.top();
    }
};

/*
双指针解法：一个先跑K-1步，第二个才开始跑。

总结：一个指针解决不了，就用两个。
*/

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead == NULL || k == 0) return NULL;
        ListNode* p_first = pListHead, *p_second = pListHead;
        while(k - 1 > 0) {
            if(p_first->next == NULL) return NULL;
            p_first = p_first->next;
            k--;
        }
        while(p_first->next) {
            p_first = p_first->next;
            p_second = p_second->next;
        }
        return p_second;
    }
};