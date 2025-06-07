#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<string> removeComments(vector<string>& source) {
    vector<string> new_source;

    bool star_comment = false;
    string code = "";
    for(auto s : source){
        cout << s << endl;
        for(int i = 0; i < s.length(); i++){
            if(!star_comment && i+1 < s.length() && s[i] == '/'){
                if(s[i+1] == '/')
                    break;
                else if(s[i+1] == '*'){
                    star_comment = true;
                    i+=2;
                }
            }

            if(star_comment && i+1 < s.length() && s[i] == '*'){
                if(s[i+1] == '/'){
                    star_comment = false;
                    i++;
                    continue;
                }
            }

            if(!star_comment && i < s.length()){
                code.push_back(s[i]);
            }
            
        }

        if(code != "" && !star_comment){
            new_source.push_back(code);
            code = "";
        }
    }

    return new_source;
}