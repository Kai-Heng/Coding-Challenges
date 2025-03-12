#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'groupSort' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<vector<int>> groupSort(vector<int> arr) {
    map<int,int> freq;
    vector<vector<int>> result;
    
    for(int i = 0; i < arr.size(); i++){
        if(freq.count(arr[i]) == 0){
            freq.insert(pair<int, int>(arr[i], 1));
        }
        else{
            freq.at(arr[i])++;
        }
    }
    
    vector<pair<int,int>> sorted(freq.begin(), freq.end());
    
    sort(sorted.begin(), sorted.end(), [] (auto &a, auto &b){
        if(a.second != b.second)
            return a.second > b.second;
        
        return a.first < b.first;
    } );
    
    
    for(auto itr : sorted){
        result.push_back({itr.first, itr.second});
    }
    
    return result;
    
}

int main(){
    vector<int> arr = {3,3,1,2,1};
    vector<vector<int>> solution = groupSort(arr);

    for(auto a : solution){
        cout << a[0] << " " << a[1] << endl;
    }

}