#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

// Brute force approach
// O(n^2 * m)
int intersect(vector<int> a, vector<int> b){
    int distinct_common = 0;
    map<int, int> a_freq;
    vector<bool>visited_b(b.size(), false);

    for(auto i : a){
        a_freq[i]++;
    }

    // O(m)
    for(int i = 0; i < b.size(); i++){
        if(a_freq.count(b[i]) != 0 && !visited_b[b[i]]){
            distinct_common++;
            visited_b[b[i]] = true;
        }
    }
    return distinct_common;
}
int numberOfComponents(vector<vector<int>>& properties, int k) {
    int connected_components = 0;
    vector<bool> visited(properties.size(), false);
    vector<int> map_graphs(properties.size(), 0);

    // O(n^2)
    for(int i = 0; i < properties.size(); i++){
        bool new_graph = false;
        for(int j = 0; j < properties.size(); j++){
            // Comparing i & j, O(m)
            if(i != j && intersect(properties[i], properties[j]) >= k){
                if(visited[j] == false && visited[i] == false){
                    new_graph = true;
                    connected_components++;
                    map_graphs[i] = connected_components;
                    map_graphs[j] = connected_components;
                }
                else if(visited[j] == true && visited[i] == false){
                    map_graphs[i] = map_graphs[j];
                }
                else if(visited[i] == true && visited[j] == false){
                    map_graphs[j] = map_graphs[i];
                }
                else{
                    if(map_graphs[i] != map_graphs[j]){
                        int temp = min(map_graphs[i], map_graphs[j]);
                        map_graphs[i] = temp;
                        map_graphs[j] = temp;
                    }
                }

                if(new_graph && visited[j]){
                    // cout << i << " " << j << endl;
                    new_graph = false;
                    connected_components--;
                }

                visited[i] = true;
                visited[j] = true;
            }
        }
        if(visited[i] == false){
            connected_components++;
            visited[i] = true;
            map_graphs[i] = connected_components;
        }
    }

    for(auto p : map_graphs){
        cout << p << " ";
    }
    cout << endl;

    sort(map_graphs.begin(), map_graphs.end());
    for(int i = 1; i < map_graphs.size(); i++){
        if(map_graphs[i] - map_graphs[i-1] > 1){
            map_graphs[i] = map_graphs[i-1] + 1;
        }
    }
    
    return map_graphs[map_graphs.size()-1];
}