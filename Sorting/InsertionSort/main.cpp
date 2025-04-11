#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

void insertionSort1(int n, vector<int> arr) {
    for(int i = 0; i < arr.size()-1; i++){
        if(arr[i] > arr[i+1]){
            int small_value = arr[i+1];
            for(int j = i; j >= 0; j--){
                if(arr[j] > small_value){
                    arr[j+1] = arr[j];
                    
                    for(auto a : arr){
                        cout << a << " ";
                    }
                    cout << endl;
                }
                else{
                    arr[j+1] = small_value;
                    break;
                }
                
                if(j == 0){
                    arr[j] = small_value;
                    break;
                }
            }
            for(auto a : arr){
                cout << a << " ";
            }
            cout << endl;
        }
    }