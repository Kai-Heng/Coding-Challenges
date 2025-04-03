#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshops{
    int start_time;
    int duration;
    int end_time;  
};

struct Available_Workshops{
    int n;
    vector<Workshops> slots;
};
//Implement the functions initialize and CalculateMaxWorkshops

Available_Workshops* initialize(int start_time[], int duration[], int num){
    Available_Workshops* s = new Available_Workshops;
    s->n = num;
    for(int i = 0; i < num; i++){
        Workshops w;
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = start_time[i] + duration[i];
        
        s->slots.push_back(w);
    }
    
    return s;
}

int CalculateMaxWorkshops(Available_Workshops* w){
    if(w->n == 0) return 0;

    sort(w->slots.begin(), w->slots.end(), [](const Workshops a, Workshops b){
        return a.end_time < b.end_time;
    });
    
    int max_workshops = 1;
    int last_session_end = w->slots[0].end_time;
    
    for(int i = 0; i < w->n; i++){
        if(w->slots[i].start_time >= last_session_end){
            max_workshops++;
            last_session_end = w->slots[i].end_time;
        }
    }
    
    return max_workshops;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}