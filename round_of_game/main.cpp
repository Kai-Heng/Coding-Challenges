#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int prev_game = p;
    int count  = 0;
    
    while(s >= prev_game){
        count++;
        s -= prev_game;
        prev_game -= d;
        if(prev_game < m){
            prev_game = m;
        }
    }
    
    return count;
}