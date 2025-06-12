#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <math.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minBackupChannels' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY backupStart
 *  2. INTEGER_ARRAY backupEnd
 */
 

int minBackupChannels(vector<int> backupStart, vector<int> backupEnd) {
    vector<pair<int,int>> timeframe;
    
    for(int i = 0; i < backupStart.size(); i++){
        timeframe.emplace_back(backupStart[i], backupEnd[i]);
    }
    
    sort(timeframe.begin(), timeframe.end(), [](const auto &a, auto &b){
        return a.first < b.first;
    });
    
    priority_queue<int, vector<int>, greater<int>> q;
    int channels = 0;
    
    for(auto [s,e] : timeframe){
        while(!q.empty() && q.top() < s){
            q.pop();
        }
        q.push(e);
        channels = max<int>(channels, q.size());
    }
    
    return channels;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string backupStart_count_temp;
    getline(cin, backupStart_count_temp);

    int backupStart_count = stoi(ltrim(rtrim(backupStart_count_temp)));

    vector<int> backupStart(backupStart_count);

    for (int i = 0; i < backupStart_count; i++) {
        string backupStart_item_temp;
        getline(cin, backupStart_item_temp);

        int backupStart_item = stoi(ltrim(rtrim(backupStart_item_temp)));

        backupStart[i] = backupStart_item;
    }

    string backupEnd_count_temp;
    getline(cin, backupEnd_count_temp);

    int backupEnd_count = stoi(ltrim(rtrim(backupEnd_count_temp)));

    vector<int> backupEnd(backupEnd_count);

    for (int i = 0; i < backupEnd_count; i++) {
        string backupEnd_item_temp;
        getline(cin, backupEnd_item_temp);

        int backupEnd_item = stoi(ltrim(rtrim(backupEnd_item_temp)));

        backupEnd[i] = backupEnd_item;
    }

    int result = minBackupChannels(backupStart, backupEnd);

    fout << result << "\n";

    fout.close();

    return 0;
}