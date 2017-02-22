/*
题目：输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

思路：分两步走，第一步先复制主链表，第二步在连接Random连接。

注意：空指针处理，包括空链表和random指空的情况

可以使用hash表优化，将A与A'对应起来，这样就不用向前向后找了
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == NULL) return NULL;
        RandomListNode* p_head = cloneMainList(pHead);
        RandomListNode* p_new = p_head, *p_old = pHead;
        while(p_new->next) {
            if(p_old->random == NULL) {
                p_new->random = NULL;
            } else {
                int k = getListNodeDistance(p_old, p_old->random);
            	if(k > 0) p_new->random = getNextKListNode(p_new, k);
            	else p_new->random = getFrontKListNode(p_head, p_new, -k);
            }
        	p_new = p_new->next;
            p_old = p_old->next;
        }
        return p_head;
    }
    
    int getListNodeDistance(RandomListNode* p_from, RandomListNode* p_to){
        int k = 0;
        RandomListNode *from = p_from, *to = p_to;
        while(from != to && from != NULL) {
            from = from->next;
            k++;
        }
        if(from != NULL) return k;
       	k = 0;
       	from = p_to, to = p_from;
        while(from != to && from != NULL){
            from = from->next;
            k--;
        }
        return k;
    }
    
    RandomListNode *getNextKListNode(RandomListNode * p_cur, int k) {
        RandomListNode *p_next_k = p_cur;
		while(k--) {
            p_next_k = p_next_k->next;
        }
        return p_next_k;
    }
    
    RandomListNode* cloneMainList(RandomListNode* pHead){
       	RandomListNode* p_head = new RandomListNode(pHead->label);
        RandomListNode* p = p_head;
        while(pHead->next){
            p->next = new RandomListNode(pHead->next->label);
            pHead = pHead->next;
            p = p->next;
        }
        return p_head;
    }
    
    RandomListNode *getFrontKListNode(RandomListNode *p_head, RandomListNode* p_cur, int k){
        RandomListNode* p_front = p_head, *p_behind = p_head;
        while(k--) {
            p_front = p_front->next;
        }
        while(p_front != p_cur) {
            p_front = p_front->next;
            p_behind = p_behind->next;
        }
        return p_behind;
    }
};


/*
剑指offer上的解法：
1. 先将每个节点复制后放在原始节点后：如A->B => A->A'->B->B'
2. 然后连接random，A如果和B相连，则A'和B'相连
3. 将链表拆分成两个链表
代码如下：

*/


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == NULL) return pHead;
        cloneNodes(pHead);
        linkRandom(pHead);
        return splitList(pHead);
    }
    
    void cloneNodes(RandomListNode* p_head) {
        while(p_head != NULL) {
            RandomListNode* new_node = new RandomListNode(p_head->label);
           	RandomListNode* tmp = p_head->next;
            p_head->next = new_node;
            new_node->next = tmp;
            p_head = p_head->next->next;
        }
    }
    
    void linkRandom(RandomListNode* p_head){
        while(p_head != NULL) {
            if(p_head->random != NULL) {
              	p_head->next->random = p_head->random->next;
            }
            p_head = p_head->next->next;
        }
    }
    
    RandomListNode* splitList(RandomListNode* p_head){
        RandomListNode* p_old = p_head;
        RandomListNode* p_new_head = p_head->next;
        RandomListNode* p_new = p_new_head;
        while(p_new->next != NULL) {
            p_old->next = p_new->next;
            p_old = p_old->next;
            p_new->next = p_old->next;
            p_new = p_new->next;
        }
        p_old->next = NULL;
        p_new->next = NULL;
        return p_new_head;
    }
    
};