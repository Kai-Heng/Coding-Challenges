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
  
class Solution {
private:
    ListNode* head;
    default_random_engine generator;
public:
    Solution(ListNode* head) {
        this->head = head;
        random_device rd;
        generator.seed(rd());
    }
    
    int getRandom() {
        ListNode* curr = head;
        int result = curr->val;
        int i = 1;

        while (curr != nullptr) {
            uniform_int_distribution<int> dist(1, i);
            if (dist(generator) == 1) {
                result = curr->val;
            }
            i++;
            curr = curr->next;
        }

        return result;
    }
};