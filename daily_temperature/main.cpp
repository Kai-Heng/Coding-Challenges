#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> wait_days(n, 0);     // answer array initialized to 0
    stack<int> st;                   // store indices of unresolved temperatures

    for (int i = 0; i < n; ++i) {
        // Resolve all previous days with a lower temperature
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev_day = st.top(); st.pop();
            wait_days[prev_day] = i - prev_day;
        }
        st.push(i);
    }

    return wait_days;
}