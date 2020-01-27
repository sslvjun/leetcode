#include "common.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *curNode = NULL;
    int carry_bit = 0;
    int sum = 0;
    
    while (l1 != NULL || l2 != NULL || carry_bit == 1) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next = NULL;
        
        if (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val;
            sum += carry_bit;
            node->val = sum % 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1 != NULL) {
            sum = l1->val;
            sum += carry_bit;
            node->val = sum % 10;
            l1 = l1->next;
        }
        else if (l2 != NULL) {
            sum = l2->val;
            sum += carry_bit;
            node->val = sum % 10;
            l2 = l2->next;
        }
        else {
            node->val = carry_bit;
            carry_bit = 0;
            sum = 0;
        }
        
        carry_bit = sum >= 10 ? 1 : 0;
        
        if (head == NULL) {
            head = node;
        }
        else {
            curNode->next = node;
        }
        curNode = node;
    }
    
    return head;
}
