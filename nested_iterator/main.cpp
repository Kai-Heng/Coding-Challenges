#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class NestedInteger {
   public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
    private:
        stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> st;
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            st.emplace(nestedList.begin(), nestedList.end());
        }
        
        int next() {
            hasNext(); // make sure we're at an integer
            int result = st.top().first->getInteger();
            ++st.top().first;
            return result;
        }
        
        bool hasNext() {
            while (!st.empty()) {
                auto &top = st.top();
                if (top.first == top.second) {
                    st.pop(); // done with this level
                }
                else if (top.first->isInteger()) {
                    return true;
                }
                else {
                    // Dive into the next list
                    auto &nestedList = top.first->getList();
                    ++top.first;
                    st.emplace(nestedList.begin(), nestedList.end());
                }
            }
            return false;
        }
    };