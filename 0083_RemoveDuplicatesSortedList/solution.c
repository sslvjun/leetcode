#include "common.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL)
        return NULL;
    
    if (head->next && head->val == head->next->val) {
        head = head->next;
        return deleteDuplicates(head);
    }
    else {
        head->next = deleteDuplicates(head->next);
    }
    
    return head;
}
