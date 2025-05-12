#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>

using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    int counter = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % 2 == 1){
            counter++;
        }
        else{
            counter = 0;
        }

        if(counter == 3){
            return true;
        }
    }
    return false;
}