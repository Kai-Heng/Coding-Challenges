#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;

    while (l1) {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    ListNode* head = nullptr;

    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;

        if (!s1.empty()) {
            sum += s1.top(); 
            s1.pop();
        }

        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }

        ListNode* node = new ListNode(sum % 10);
        node->next = head;
        head = node;

        carry = sum / 10;
    }

    return head;
}