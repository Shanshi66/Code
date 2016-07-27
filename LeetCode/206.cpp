/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* front = head->next;
        head->next = NULL;
        while(front != NULL){
            ListNode* tmp = front->next;
            front->next = head;
            head = front;
            front = tmp;
        }
        return head;
    }
};