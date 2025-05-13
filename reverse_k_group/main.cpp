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
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1 || !head) return head;

    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    ListNode* node = head;
    while (node) {
        stack<ListNode*> st;
        ListNode* temp = node;
        
        // Try to collect k nodes
        for (int i = 0; i < k && temp; ++i) {
            st.push(temp);
            temp = temp->next;
        }

        // Not enough nodes to reverse → attach as-is
        if (st.size() < k) {
            curr->next = node;
            break;
        }

        // Pop and attach reversed group
        while (!st.empty()) {
            curr->next = st.top();
            st.pop();
            curr = curr->next;
        }

        // Connect to the next group
        curr->next = temp;

        // Move to the next group
        node = temp;
    }

    return dummy->next;
}