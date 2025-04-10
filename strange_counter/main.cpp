#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

long strangeCounter(long t) {
    long cycle_init_value = 3;
    long time = 1;
    long prev_time = -1;
    long prev_cycle_init_value;
    while(t >= time){
        prev_cycle_init_value = cycle_init_value;
        prev_time = time;
        cycle_init_value *= 2;
        time = cycle_init_value - 2;
    }
    
    return prev_time + prev_cycle_init_value - t;
}