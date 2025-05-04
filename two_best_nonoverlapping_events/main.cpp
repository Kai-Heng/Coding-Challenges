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
#include <unordered_set>

using namespace std;

int maxTwoEvents(vector<vector<int>>& events) {
    // sort by start time
    sort(events.begin(), events.end(),
         [](const auto& a, const auto& b){ return a[0] < b[0]; });

    int n = events.size();
    vector<int> sufMax(n);               // suffix max of value
    sufMax[n-1] = events[n-1][2];
    for (int i = n-2; i >= 0; --i)
        sufMax[i] = max(sufMax[i+1], events[i][2]);

    int answer = 0;

    for (int i = 0; i < n; ++i) {
        int val1 = events[i][2];
        answer = max(answer, val1);      // maybe take only one event

        // binary‑search the first event whose start > current end
        int nextIdx = upper_bound(events.begin(), events.end(),
                                  events[i][1],
                                  [](int endTime, const auto& ev){
                                      return endTime < ev[0];
                                  }) - events.begin();

        if (nextIdx < n) {               // a non‑overlapping event exists
            answer = max(answer, val1 + sufMax[nextIdx]);
        }
    }
    return answer;
}