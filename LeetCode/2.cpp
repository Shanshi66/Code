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
    int getLength(ListNode *l){
        int len = 0;
        while(l != NULL) {
            ++len;
            l = l->next;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1), len2 = getLength(l2);
        if(len1 >= len2) {
            addNumber(l1, l2);
            return l1;
        }
        else {
            addNumber(l2, l1);
            return l2;
        }
    }
    // void addNumber(ListNode* l1, ListNode* l2){
    //     int jin = 0;
    //     while(l2 != NULL){
    //         l1->val += l2->val + jin;
    //         if(l1->val >= 10) {
    //             jin = 1;
    //             l1->val %= 10;
    //         } else {
    //             jin = 0;
    //         }
    //         if(l2->next != NULL) {
    //             l1 = l1->next;
    //             l2 = l2->next;
    //         } else break;
    //     }
    //     while(jin > 0) {
    //         if(l1->next != NULL) {
    //             l1->next->val += jin;
    //             if(l1->next->val >= 10) {
    //                 l1->next->val %= 10;
    //                 jin = 1;
    //             } else {
    //                 jin = 0;
    //             }
    //         } else {
    //             l1->next = new ListNode(jin);
    //             jin = 0;
    //         }
    //         l1 = l1->next;
    //     }
    // }
    void addNumber(ListNode *l1, ListNode *l2) {
        int jin = 0;
        ListNode *pre = NULL;
        while(l1 != NULL) {
            if(l2 != NULL) l1->val += l2->val + jin;
            else l1->val += jin;
            if(l1->val >= 10) {
                l1->val -= 10;
                jin = 1;
            } else jin = 0;
            pre = l1;
            l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        if(jin > 0) pre->next = new ListNode(jin);
    }
};