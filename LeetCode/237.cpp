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
    // 将当前节点变成下一个节点，删除下一个节点
    void deleteNode(ListNode* node) {
        if(node == NULL) return;
        else{
            node->val = node->next->val;
            ListNode* p = node->next;
            node->next = node->next->next;
            delete p;
        }
    }
};