#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

vector<vector<string>> solution(vector<string> repository, string customerQuery){
    vector<vector<string>> results;

    if(repository.empty() || customerQuery.length() < 2 ) return results;

    vector<string> sorted_repository;

    for(auto item : repository){ // O(N)
        transform(item.begin(), item.end(), item.begin(), [](unsigned char c){return tolower(c);});
        sorted_repository.push_back(item);
    }
    
    sort(sorted_repository.begin(), sorted_repository.end()); // O(NlogN)
    
    for(int i = 2; i <= customerQuery.length(); i++){ //O(N^2)
        string sub = customerQuery.substr(0, i);
        vector<string> r;
        for(auto item : sorted_repository){

            if(r.size() == 3) break;

            if(sub.compare(item.substr(0,i)) == 0){
                r.push_back(item);
            }
        }

        results.push_back(r);
    }

    return results;
}

int main(){
    vector<string> repository;
    string customerQuery;
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        
        repository.push_back(temp);
    }
    cin >> customerQuery;

    transform(customerQuery.begin(), customerQuery.end(), customerQuery.begin(), [](unsigned char c){return tolower(c);});

    vector<vector<string>> searchResults = solution(repository, customerQuery);
    for(vector<string> &result : searchResults){
        string temp_str = "";
        temp_str += "[";
        for(string &s : result){
            temp_str += "\""+ s + "\""+ ", "; 
        }
        temp_str = temp_str.substr(0,temp_str.length()-2);
        temp_str += "]";
        cout << temp_str << endl;
    }

    return 0;
}