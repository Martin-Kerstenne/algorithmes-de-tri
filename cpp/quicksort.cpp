#include "../sort.hpp"
#include <vector>
#include <iostream>

using namespace std;

void sort_algorithm(vector<int> &v) {
    if(v.size() >= 1) {
        int pivot = v[0];
        vector<int> v1, v2, v3;
        for (int x : v) {
            if(x < pivot)
                v1.push_back(x);
            else if (x > pivot)
                v3.push_back(x);
            else // x == pivot
                v2.push_back(x);
        }
        sort_algorithm(v1);
        sort_algorithm(v3);
        v = v1;
        v.insert(v.end(), v2.begin(), v2.end());
        v.insert(v.end(), v3.begin(), v3.end());
    }
}
