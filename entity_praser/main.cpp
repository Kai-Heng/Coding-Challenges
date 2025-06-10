#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
#include <random>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

string entityParser(string text) {
    int first_amp = false;
    string keyword = "";
    string newText = "";
    for(int i = 0; i < text.length(); i++){
        if(text[i] == '&' && !first_amp){
            keyword += text[i];
            first_amp = true;
        }
        else if(first_amp){
            
            if(text[i] == '&'){
                newText += keyword;
                keyword = "&";
            }
            else if(text[i] != ';'){
                keyword += text[i];
            }
            else{
                if(keyword == "&quot"){
                    newText += "\"";
                }
                else if(keyword == "&apos"){
                    newText += "\'";
                }
                else if(keyword == "&amp"){
                    newText += "&";
                }
                else if(keyword == "&gt"){
                    newText += ">";
                }
                else if(keyword == "&lt"){
                    newText += "<";
                }
                else if(keyword == "&frasl"){
                    newText += "/";
                }
                else{
                    newText += keyword + ";";
                }

                keyword = "";
                first_amp = false;
            }
            
        }
        else{
            newText += text[i];
        }
    }



    return newText + keyword;
}