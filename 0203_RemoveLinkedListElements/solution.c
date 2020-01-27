#include "common.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL)
        return NULL;
    
    head->next = removeElements(head->next, val);
    if (head->val == val)
        return head->next;
    else
        return head;
}
