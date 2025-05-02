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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* merged = dummy;

    while(list1 && list2){
        if(list1->val <= list2->val){
            dummy->next = list1;
            dummy = dummy->next;
            list1 = list1->next;
        }
        else{
            dummy->next = list2;
            dummy = dummy->next;
            list2 = list2->next;
        }
    }

    while(list1){
        dummy->next = list1;
        dummy = dummy->next;
        list1 = list1->next;
    }

    while(list2){
        dummy->next = list2;
        dummy = dummy->next;
        list2 = list2->next;
    }

    return merged->next;
}