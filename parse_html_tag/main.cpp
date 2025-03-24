#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    cin.ignore();
    
    map<string, string> attribute_map;
    vector<string> tag_path;
    
    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);

        // Remove '<' and '>'
        if (line[1] == '/') {
            // This is a closing tag.
            tag_path.pop_back();
        }
        else {
            // Opening tag:
            stringstream ss(line);
            string firstToken;
            ss >> firstToken;  // e.g. "<tag1>" or "<tag1"
            
            // Remove the leading '<'
            string tagname = firstToken.substr(1);
            
            // If there is a trailing '>', remove it
            if (!tagname.empty() && tagname.back() == '>') {
                tagname.pop_back();
            }
            
            // Now push the clean tag name
            tag_path.push_back(tagname);
            
            // Build the full path (e.g. "tag1.tag2")
            string full_path;
            for (int j = 0; j < (int)tag_path.size(); j++) {
                if (j > 0) full_path += ".";
                full_path += tag_path[j];
            }
            
            // Now parse any attributes
            // Every attribute should come in as: attrName = "attrValue"
            // possibly with the last one ending in "...">.
            // So you can read them in a loop:
            string attr_name, equals, attr_value;
            while (ss >> attr_name >> equals >> attr_value) {
                // If the value ends with '>', remove that trailing '>' 
                // before stripping quotes.  (This handles the last attribute on the tag.)
                if (!attr_value.empty() && attr_value.back() == '>') {
                    attr_value.pop_back(); 
                }
                // Remove the surrounding quotes from attr_value
                // e.g. "hello" becomes hello
                if (attr_value.size() >= 2 && attr_value.front() == '"' && attr_value.back() == '"') {
                    attr_value = attr_value.substr(1, attr_value.size() - 2);
                }
                // Store in map
                attribute_map[full_path + "~" + attr_name] = attr_value;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        if (attribute_map.find(query) != attribute_map.end()) {
            cout << attribute_map[query] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
