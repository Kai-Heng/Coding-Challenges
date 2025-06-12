#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare{
    bool operator()(ListNode* a, ListNode* b) {
        return a->val >= b->val;
    }
};
    
ListNode* sortList(ListNode* head) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> q;
    ListNode* curr = head;
    while(curr){
        q.push(curr);
        curr = curr->next;
    }

    ListNode* dummy = new ListNode(0);
    ListNode* sorted = dummy;
    while(!q.empty()){
        dummy->next = q.top();
        q.pop();
        dummy = dummy->next;
    }
    dummy->next = nullptr;

    return sorted->next;
}