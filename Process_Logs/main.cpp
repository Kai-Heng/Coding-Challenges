#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'processLogs' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY logs
 *  2. INTEGER threshold
 */

vector<string> processLogs(vector<string> logs, int threshold) {
    map<int,int> user_occurrence;
    vector<string> result;
    for(int i = 0; i < logs.size(); i++){
        stringstream ss(logs[i]);
        string digit;
        vector<int> digits;
        
        while(ss >> digit){
            digits.push_back(stoi(digit));
        }
        
        if(digits[0] != digits[1]){
            if(user_occurrence.count(digits[0]) == 0 && user_occurrence.count(digits[1]) == 0){
                user_occurrence.insert(pair<int,int>(digits[0], 1));
                user_occurrence.insert(pair<int,int>(digits[1], 1));
            }
            else if(user_occurrence.count(digits[0]) != 0 && user_occurrence.count(digits[1]) == 0){
                user_occurrence.at(digits[0])++;
                user_occurrence.insert(pair<int,int>(digits[1], 1));
            }
            else if(user_occurrence.count(digits[0]) == 0 && user_occurrence.count(digits[1]) != 0){
                user_occurrence.insert(pair<int,int>(digits[0], 1));
                user_occurrence.at(digits[1])++;
            }
            else{
                user_occurrence.at(digits[0])++;
                user_occurrence.at(digits[1])++;
            }
        }
        else{
            if(user_occurrence.count(digits[0]) == 0){
                user_occurrence.insert(pair<int,int>(digits[0], 1));
            }
            else{
                user_occurrence.at(digits[0])++;
            }
        }
    }
    
    for(auto itr : user_occurrence){
        if(itr.second >= threshold){
            result.push_back(to_string(itr.first));
        }
    }
    
    return result;
}

int main()
{
    vector<string> logs = {"88 99 200", "99 88 300", "12 12 15"};
    int threshold = 2;

    vector<string> solution = processLogs(logs, threshold);

    for(auto s : solution){
        cout << s << endl;
    }


    return 0;
}


