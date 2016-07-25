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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *new_head = head->next, *tail = NULL;
        while(head != NULL && head->next != NULL){
            if(tail) tail->next = head->next; 
            ListNode* tmp = head->next->next;
            head->next->next = head;
            head->next = tmp;
            tail = head;
            head = head->next;
        }
        return new_head;
    }
};