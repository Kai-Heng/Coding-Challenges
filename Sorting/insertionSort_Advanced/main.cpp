#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>

using namespace std;

class FenwickTree {
    public:
        vector<long> tree;
        long size;
    
        FenwickTree(long n) {
            size = n + 2;
            tree.resize(size, 0);
        }
    
        void update(long index, long value) {
            while (index < size) {
                tree[index] += value;
                index += index & -index;
            }
        }
    
        long query(long index) {
            long result = 0;
            while (index > 0) {
                result += tree[index];
                index -= index & -index;
            }
            return result;
        }
    
        long queryRange(long left, long right) {
            return query(right) - query(left - 1);
        }
};
    
long insertionSort(vector<long> arr) {
    long n = arr.size();
    vector<long> sorted = arr;

    // Coordinate compression
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    unordered_map<long, long> compress;
    for (long i = 0; i < sorted.size(); ++i) {
        compress[sorted[i]] = i + 1; // 1-based indexing
    }

    FenwickTree bit(sorted.size());
    long shifts = 0;

    for (long i = 0; i < n; ++i) {
        long idx = compress[arr[i]];
        // Count number of elements already in BIT that are greater than arr[i]
        shifts += bit.queryRange(idx + 1, sorted.size());
        bit.update(idx, 1);
    }

    return shifts;
}