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
 * Complete the 'numberOfItems' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY startIndices
 *  3. INTEGER_ARRAY endIndices
 */

vector<int> numberOfItems(string s, vector<int> startIndices, vector<int> endIndices) {
    int firstComp = -1;
    int k_firstComp = -1;
    int stars = 0;
    map<int,int> map_left_comp;
    map<int,int> map_right_comp;
    map<int,int> comp_stars;
    int k = s.length()-1;
    
    cout << s << endl;
    
    /**
    *|**|*****|**
    Comp_star:
    1 0
    4 2
    10 7
    
    map_left:
    comp = 1,
    2 1
    3 1
    comp = 4,
    5 4
    6 4
    7 4
    8 4
    9 4
    comp = 10,
    11 10
    12 10
    
    map_right:
    comp = 10,
    9 10
    8 10
    7 10
    6 10
    5 10
    comp = 4,
    3 4
    2 4
    comp = 1,
    0 1
    
    startIndices: 1
    endindex: 12
    **/
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '|' && firstComp < 0){
            firstComp = i;
            comp_stars.insert(pair<int,int>(firstComp, 0));
        }
        else if(s[i] == '*' && firstComp >= 0){
            stars++;
            map_left_comp.insert(pair<int,int>(i,firstComp));
        }
        else if(s[i] == '|' && firstComp >= 0){
            firstComp = i;
            comp_stars.insert(pair<int,int>(firstComp, stars));
        }
        
        if(s[k] == '|'){
            k_firstComp = k;
        }
        else if(s[k] == '*' && k_firstComp >= 0){
            map_right_comp.insert(pair<int,int>(k,k_firstComp));
        }
        
        k--;
    }
    
    // cout << "Star Comp: "<<endl;
    // for(auto star : comp_stars){
    //     cout << star.first << " " << star.second << endl;
    // }
    
    // cout << "Left Comp: "<<endl;
    // for(auto left : map_left_comp){
    //     cout << left.first << " " << left.second << endl;
    // }
    
    // cout << "Right Comp: "<<endl;
    // for(auto right : map_right_comp){
    //     cout << right.first << " " << right.second << endl;
    // }
    
    vector<int> result;
    for(int i = 0; i < startIndices.size(); i++){
        int startPos = startIndices[i] - 1;
        int endPos = endIndices[i] - 1;
        int start_star = 0;
        int end_star = 0;
        
        if(comp_stars.count(startPos) != 0){
            start_star = comp_stars.at(startPos);
        }
        else if(map_right_comp.count(startPos) != 0){
            start_star = comp_stars.at(map_right_comp.at(startPos));
        }
        
        if(comp_stars.count(endPos) != 0){
            end_star = comp_stars.at(endPos);
        }
        else if(map_left_comp.count(endPos) != 0){
            end_star = comp_stars.at(map_left_comp.at(endPos));
        }
        if(start_star >= end_star){
            result.push_back(0);
        }
        else{
            result.push_back(end_star-start_star);
        }
    }
    
    return result;
}

int main()
{
    string s = "*|**|*****|**";
    vector<int> startIndices = {1,2};
    vector<int> endIndices = {12,10};

    vector<int> solutions = numberOfItems(s, startIndices, endIndices);

    for(auto s : solutions){
        cout << s << endl;
    }

    return 0;
}

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }
