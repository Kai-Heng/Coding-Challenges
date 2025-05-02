#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* curr = head;
    vector<ListNode*> nodes;
    while(curr){
        nodes.push_back(curr);
        curr = curr->next;
    }
    if(nodes.size() == 1){
        return nullptr;
    }
    else if(nodes.size()-n == 0){
        return head->next;
    }
    else if(nodes.size()-n == nodes.size()-1){
        nodes[nodes.size()-n-1]->next = nullptr;
    }
    else{
        nodes[nodes.size()-n-1]->next = nodes[nodes.size()-n+1];
    }

    return head;
}