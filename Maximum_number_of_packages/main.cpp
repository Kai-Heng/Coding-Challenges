/**
You are given an array, say cost, of item costs: [cost_1, cost_2, cost_3, ..., cost_n]. 
You can create “packages,” each of which can contain at most two items, and the cost of a package is the sum of the item(s) it contains.

Your goal: Maximize the number of packages (think of it as grouping the items into pairs or singles), 
subject to the requirement that all packages must have the same total cost. Each item can only appear 
in exactly one package (no item can be reused in a different package).

For example, if you have costs [2, 2, 2, 2], you might form packages (2,2) and (2,2), 
each summing to 4, giving 2 packages. But if you had [1,1,2,2], 
you might do packages (1,2) and (1,2) if that helps maximize the number of packages of a consistent sum.

Key points to consider:

A package can either be one item by itself or two items combined.
All packages must share the exact same total sum.
We want to make as many packages as possible from the items.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int max_packages(vector<int> arr){
    map<int,int> cost_freq;
    int sum = 0;
    int whole_average = 0;
    int packages = 0;
    for(int i = 0; i < arr.size(); i++){
        if(cost_freq.count(arr[i]) == 0){
            cost_freq.insert(pair<int,int>(arr[i], 1));
        }
        else{
            cost_freq.at(arr[i])++;
        }
        sum += arr[i];
    }

    if(cost_freq.size() == 1){
        return cost_freq.begin()->second;
    }

    sort(arr.begin(), arr.end());

    for(int i = arr.size(); i >= 1; i--){
        whole_average = sum/i;

        if(whole_average >= arr[arr.size()-1]){
            break;
        }
    }
    
    cout << "Cost: " << whole_average << endl;

    reverse(arr.begin(), arr.end());

    int idx = 0;
    int useless = 0;
    while(idx < arr.size()){
        int temp = whole_average - arr[idx];
        
        if(temp == arr[idx] && cost_freq.at(temp) > 1){
            cout << "[" << arr[idx] << ", " << temp << "]" << endl;
            cost_freq.at(arr[idx])--;
            cost_freq.at(temp)--;
            packages++;
        }
        else if(temp != 0 && temp != arr[idx]){
            if(cost_freq.count(temp) == 0 || cost_freq.at(temp) == 0){
                useless++;
            }
            else if(cost_freq.at(arr[idx]) > 0 && cost_freq.at(temp) > 0){
                cout << "[" << arr[idx] << ", " << temp << "]" << endl;
                cost_freq.at(arr[idx])--;
                cost_freq.at(temp)--;
                packages++;
            }
            else{
                break;
            }
        }
        else{
            if(cost_freq.at(arr[idx]) > 0 && temp == 0){
                cost_freq.at(arr[idx])--;
                cout << "[" << arr[idx] << "]" << endl;
                packages++;
            }
            else{
                break;
            }
        }

        // for(auto a : cost_freq){
        //     cout << a.first << " " << a.second << endl;
        // }
        idx++;
    }

    return packages;
}

int main(){
    vector<int> arr = {1,1,1,1,1,2,2,2,2,2,2,2,3};

    cout << max_packages(arr) << endl;
}
