#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2){
    int left = 0;
    int right = 0;
    vector<int> sorted;
    while(left < arr1.size() && right < arr2.size()){
        if(arr1[left] <= arr2[right]){
            sorted.push_back(arr1[left]);
            left++;
        }
        else{
            sorted.push_back(arr2[right]);
            right++;
        }
    }

    while(left < arr1.size()){
        sorted.push_back(arr1[left]);
        left++;
    }

    while(right < arr2.size()){
        sorted.push_back(arr2[right]);
        right++;
    }

    return sorted;
}

vector<int> divide(vector<int> arr){
    if(arr.size() <= 1) return arr;

    int mid = arr.size()/2;
    vector<int> left(arr.begin(), arr.begin()+mid);
    vector<int> right(arr.begin()+mid, arr.end());

    return merge(divide(left), divide(right));
}

int main(){
    vector<int> arr = {5,3,6,21,5,1,10};
    vector<int> sorted = divide(arr);
    for(auto i : sorted){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}