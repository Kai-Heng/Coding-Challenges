#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(vector <int> &arr) {
	// Complete this function
    int pivot = arr[0];
    vector<int> left;
    vector<int> right;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] <= pivot){
            left.push_back(arr[i]);
        }
        else{
            right.push_back(arr[i]);
        }
    }
    
    // for(auto s : left){
    //     cout << s << " ";
    // }
    // cout << endl;
    // cout << pivot << endl;
    // for(auto s : right){
    //     cout << s << " ";
    // }
    // cout << endl;
    
    if(!left.empty())
        quickSort(left);
        
    if(!right.empty())
        quickSort(right);
    
    vector<int> sorted(arr.size());
    
    sorted = left;
    sorted.push_back(pivot);
    sorted.insert(sorted.end(),right.begin(), right.end());
    
    arr = sorted;
    if(arr.size() > 1){
        for(auto s : arr){
            cout << s << " ";
        }
        cout << endl;
    }

    return;
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
