#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>

using namespace std;

long sum_of_fib_even(long n){
    long sum = 0;
    long first_index = 1;
    long second_index = 2;
    while(second_index < n){
        if(second_index % 2 == 0){
            sum += second_index;
        }
        long temp = second_index;
        second_index = first_index + second_index;
        first_index = temp;
    }

    return sum;
}