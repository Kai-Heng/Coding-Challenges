#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

double findMedian(vector<int> &count, int d) {
    int median1 = -1, median2 = -1;
    int sum = 0;

    for (int i = 0; i < 201; i++) {  // Loop through frequency array
        sum += count[i];

        if (median1 == -1 && sum >= d / 2 + (d % 2)) {
            median1 = i;  // First median element (for both even and odd cases)
            cout << median1 << " " << median2 << endl;
        }
        if (median2 == -1 && sum >= d / 2 + 1) {
            median2 = i;  // Second median element (for even case)
            break;
        }
    }

    return (d % 2 == 0) ? (median1 + median2) / 2.0 : median1;
}

int activityNotifications(vector<int> expenditure, int d) {
    int notification = 0;
    vector<int> count(201, 0); // Frequency array (0-200 possible values)

    // Initialize frequency array with first `d` elements
    for (int i = 0; i < d; i++) {
        count[expenditure[i]]++;
    }
    
    // D = 5
    // 1,2,3,4,5
    // j = i - d
    // i = 5, j = 0,1,2,3,4
    // i = 6, j = 1,2,3,4,5
    
    // vector<int> sub_exp(expenditure.begin(), expenditure.begin()+d);
    // cout << endl;
    for(int i = d; i < expenditure.size(); i++){
        // if(i != d){
        //     sub_exp.erase(sub_exp.begin());
        //     sub_exp.push_back(expenditure[i-1]);
        // }
        // sort(sub_exp.begin(), sub_exp.end());
        double median = findMedian(count, d);
        cout << median << endl;
        
        if(expenditure[i] >= 2*median){
            notification++;
        }
        
        // Update frequency array (Sliding Window)
        count[expenditure[i]]++;         // Add new element
        count[expenditure[i - d]]--;     // Remove old element
    }
    
    return notification;
}