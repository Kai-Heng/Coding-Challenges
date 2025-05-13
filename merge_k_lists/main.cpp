#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
};

// Min-heap O(n log k)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    for (ListNode* node : lists) {
        if (node) pq.push(node);
    }

    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        curr->next = node;
        curr = curr->next;

        if (node->next) {
            pq.push(node->next);
        }
    }

    return dummy->next;
}

// O(KN)
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    int null_tracker = 0;
    ListNode* dummy = new ListNode(0);
    ListNode* merged = dummy;
    
    for(int i = 0; i < k; i++){
        if(lists[i] == nullptr) null_tracker++;
    }
    if(null_tracker == k) return nullptr;

    while(null_tracker < k && k > 0){
        ListNode* small = new ListNode(1000000);
        int id = -1;

        for(int i = 0; i < k; i++){
            if(lists[i] != nullptr && lists[i]->val < small->val){
                small = lists[i];
                id = i;
            }
        }
        dummy->next = small;
        lists[id] = lists[id]->next;
        dummy = dummy->next;

        if(lists[id] == nullptr){
            null_tracker++;
        }
    }
    return merged->next;
}