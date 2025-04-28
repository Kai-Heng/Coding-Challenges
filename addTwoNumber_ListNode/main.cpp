#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           ListNode* dummy = new ListNode(0); 
           ListNode* newList = dummy;
           int overload = 0;
           while(l1 && l2){
            ListNode* sum = new ListNode(l1->val + l2->val + overload);
            overload = sum->val / 10;
    
            if(overload){
                sum->val = sum->val % 10;
            }
            l1 = l1->next;
            l2 = l2->next;
            dummy->next = sum;
            dummy = dummy->next;
           }
    
           while(l1){
            ListNode* sum = new ListNode(l1->val + overload);
            overload = sum->val / 10;
    
            if(overload){
                sum->val = sum->val % 10;
            }
            l1 = l1->next;
            dummy->next = sum;
            dummy = dummy->next;
           }
    
           while(l2){
            ListNode* sum = new ListNode(l2->val + overload);
            overload = sum->val / 10;
    
            if(overload){
                sum->val = sum->val % 10;
            }
            l2 = l2->next;
            dummy->next = sum;
            dummy = dummy->next;
           }
    
           if(overload){
            dummy->next = new ListNode(overload);
           }
    
           return newList->next;
        }
    };