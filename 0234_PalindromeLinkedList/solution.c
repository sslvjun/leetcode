#include "common.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
    struct ListNode *fast = head, *slow = head, *prev = NULL;
    
    while (fast) {  // find mid node
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
    
    while (slow) {  // reverse
        struct ListNode *tmp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = tmp;
    }
    
    while (head && prev) {  // check
        if (head->val != prev->val)
            return false;
        
        head = head->next;
        prev = prev->next;
    }
    
    return true;
}
