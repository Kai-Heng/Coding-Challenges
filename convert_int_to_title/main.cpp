#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

string convertToTitle(int columnNumber) {
    string title = "";
    
    while(columnNumber > 0){
        columnNumber--;
        int remainder = columnNumber % 26;
        title.insert(title.begin(), char(remainder + 'A'));
        columnNumber /= 26;
    }
    

    
    return title;
}