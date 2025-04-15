#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

int minimumLoss(vector<long> price) {
    int n = price.size();
    int min_loss = INFINITY;
    set<long> loss_tracker;
    for(long i = 0; i < n; i++){
        long upper = *loss_tracker.upper_bound(price[i]);
        long loss = upper - price[i];
        
        if(loss > 0 && loss < min_loss){
            min_loss = loss;
        }
        
        loss_tracker.insert(price[i]);
    }

    return min_loss;
}