#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <bitset>

using namespace std;

long taumBday(long b, long w, long bc, long wc, long z) {

    if(bc > (wc + z)){
        return (w * wc) + (b * (wc+z));
    }
    else if(wc > (bc + z)){
        return (b*bc) + (w * (bc+z));
    }
    
    
    return b*bc + w*wc;
}