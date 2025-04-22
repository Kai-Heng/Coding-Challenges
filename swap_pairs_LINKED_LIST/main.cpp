#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    
    // a->b->c->d
    // curr = a
    // cur_next = b
    while(head && head->next){
        ListNode* curr = head;
        ListNode* next_curr = head->next;
        
        // a->c->d
        curr->next = next_curr->next; // a->next = b->next = c
        // b->a->c->d
        next_curr->next = curr; // b->next = a
        prev->next = next_curr;
        
        prev = curr;
        head = curr->next;
    }
    
    return dummy->next;
}