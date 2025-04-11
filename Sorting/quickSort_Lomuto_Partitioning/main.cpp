#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/**

// Sorts (a portion of) an array, divides it into partitions, then sorts those
algorithm quicksort(A, lo, hi) is 
  // Ensure indices are in correct order
  if lo >= hi || lo < 0 then 
    return
    
  // Partition array and get the pivot index
  p := partition(A, lo, hi) 
      
  // Sort the two partitions
  quicksort(A, lo, p - 1) // Left side of pivot
  quicksort(A, p + 1, hi) // Right side of pivot

// Divides array into two partitions
algorithm partition(A, lo, hi) is 
  pivot := A[hi] // Choose the last element as the pivot

  // Temporary pivot index
  i := lo

  for j := lo to hi do 
    // If the current element is less than or equal to the pivot
    if A[j] <= pivot then 
      // Swap the current element with the element at the temporary pivot index
      swap A[i] with A[j]
      // Move the temporary pivot index forward
      i := i + 1

  // Swap the pivot with the last element
  swap A[i] with A[hi]
  return i // the pivot index
  
*/

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    
    int i = low;
    
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low >= high || low < 0){
        return;
    }
    
    int p = partition(arr, low, high);
    for(auto s : arr){
        cout << s << " ";
    }
    cout << endl;
    
    quickSort(arr, low, p - 1); // Left side of pivot
    quickSort(arr, p + 1, high); // Right side of pivot
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, arr.size()-1);

    return 0;
}

