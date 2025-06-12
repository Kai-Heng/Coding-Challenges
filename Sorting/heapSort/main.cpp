#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[max]){
        max = left;
    }

    if(right < n && arr[right] > arr[max]){
        max = right;
    }

    if(max != i){
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void buildHeap(vector<int> &arr){
    for(int i = arr.size()/2-1; i >= 0; i--){
        heapify(arr, arr.size(), i);
    }
}

void heapsort(vector<int> &arr){
    buildHeap(arr);
    for(int i = arr.size()-1; i >=0 ; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}



int main(){
    vector<int> arr = {5,3,6,21,5,1,10};
    heapsort(arr);
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}