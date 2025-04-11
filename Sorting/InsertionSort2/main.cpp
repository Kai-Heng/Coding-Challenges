#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void insertionSort2(int n, vector<int> arr) {
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            for(int j = i+1; j >= 1; j--){
                if(arr[j] < arr[j-1]){
                    swap(arr[j], arr[j-1]);
                }
            }
        }
        for(auto a : arr){
            cout << a << " ";
        }
        cout << endl;
    }
}