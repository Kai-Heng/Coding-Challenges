#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

int getMaxVisitableWebpages(int N, vector<int> L) {
    // Write your code here
    vector<int> visited(N, 0); // 0 = not visited, 1 = visiting, 2 = visited
    vector<int> memo(N, 0);    // memoized results
    int maxPages = 0;

    function<int(int)> dfs = [&](int node) -> int {
        if (visited[node] == 2) return memo[node]; // already processed
        if (visited[node] == 1) { // found a cycle
            // Calculate cycle length
            int cycle_length = 0;
            int current = node;
            do {
                cycle_length++;
                current = L[current] - 1;
            } while (current != node);
            // Mark all nodes in the cycle
            current = node;
            do {
                visited[current] = 2;
                memo[current] = cycle_length;
                current = L[current] - 1;
            } while (current != node);
            return cycle_length;
        }

        visited[node] = 1; // mark as visiting
        int next = L[node] - 1; // convert to 0-based index
        int result = dfs(next);
        if (visited[node] == 1) { // node is not part of a cycle
            memo[node] = result + 1;
            visited[node] = 2;
        }
        return memo[node];
    };

    for (int i = 0; i < N; ++i) {
        if (visited[i] == 0) {
            maxPages = max(maxPages, dfs(i));
        }
    }

    return maxPages;
  }