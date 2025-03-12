#include <regex>
#include <iostream>

using namespace std;

regex regularExpression("^(.)$|^(.).*\\2$");
// Group 1 ^(.)$ - matches exactly one character for only one character input
// Group 2 ^(.).*\\2$ - matches the first and last character in group 2
// - ^ anchors at start
// - (.) captures the first character
// - .* matches any characters in the between
// - \2 ensures the last character matches the group 2
// - $ anchors at end

int main(){
    string s = "aba";

    if(regex_match(s, regularExpression)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
}