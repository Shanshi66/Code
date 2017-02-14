/*
题目：输入一个链表，从尾到头打印链表每个节点的值。
思路：遍历的时候先用栈保存，然后再弹出。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> output;
        if(head == NULL) return output;
        stack<ListNode*> nodes_stack;
        ListNode *p = head;
        while(p != NULL) {
            nodes_stack.push(p);
            p = p->next;
        }
        while(!nodes_stack.empty()) {
            ListNode *top = nodes_stack.top();
            output.push_back(top->val);
            nodes_stack.pop();
        }
        return output;
    }
};