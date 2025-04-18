#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

vector<string> removeComments(vector<string>& source) {
    vector<string> result;
    bool inBlock = false;
    string newline;

    for (string& line : source) {
        int i = 0;
        if (!inBlock) newline = "";
        while (i < line.size()) {
            if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i+1] == '*') {
                inBlock = true;
                i += 2;
            } else if (inBlock && i + 1 < line.size() && line[i] == '*' && line[i+1] == '/') {
                inBlock = false;
                i += 2;
            } else if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i+1] == '/') {
                break; // line comment: ignore rest of the line
            } else if (!inBlock) {
                newline += line[i++];
            } else {
                i++; // ignore characters inside block comment
            }
        }
        if (!inBlock && !newline.empty()) {
            result.push_back(newline);
        }
    }

    return result;
}