#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

unordered_map<string, multiset<string>> graph;
vector<string> result;

void dfs(string airport) {
    while (!graph[airport].empty()) {
        auto next = *graph[airport].begin();  // smallest lexical destination
        graph[airport].erase(graph[airport].begin());
        dfs(next);
    }
    result.push_back(airport);  // post-order push
}
vector<string> findItinerary(vector<vector<string>>& tickets) {
    // Build graph
    for (auto& ticket : tickets) {
        graph[ticket[0]].insert(ticket[1]);
    }

    dfs("JFK");
    reverse(result.begin(), result.end());
    return result;
}