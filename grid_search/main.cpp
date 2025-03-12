#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
    int j = 0;
    int last_row = -1;
    int last_col = -1;
    for(int i = 0; i < G.size(); i++){
        int found = G[i].find(P[j]);
        if(found != string::npos){
            if(last_row < 0 && last_col < 0){
                j++;
                last_col = found;
                last_row = i;
            }
            else if(found!=last_col){
                if(G[i-1].find(P[j-1], found) != string::npos){
                    last_col = found;
                    last_row = i;
                    j++;
                }
                else if(G[i].find(P[0]) != string::npos){
                    j = 0;
                    last_row = i;
                    last_col = found;
                    j++;
                }
                else{
                    j = 0;
                    last_row = -1;
                    last_col = -1;
                }
                
            }
            else{
                j++;
                last_col = found;
                last_row = i;
            }
            cout << last_row << endl;
            cout << last_col << endl;
        }
        else{
            j = 0;
            last_row = -1;
            last_col = -1;
            
            if(G[i].find(P[j]) != string::npos){
                i--;
            }
        }
        
        if(j > P.size() - 1){
            return "YES";
        }
    }
    return "NO";
}

int main(){
    vector<string> G = {
        "123412",
        "561212",
        "123634",
        "781288"
    };
    vector<string> P = {
        "12",
        "34"
    };

    cout << gridSearch(G,P) << endl;
}