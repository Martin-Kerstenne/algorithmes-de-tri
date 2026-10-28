#include "../sort.hpp"
#include <vector>
#include <iostream>
using namespace std;

void sort_algorithm(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i;
        while (j > 0 && v[j - 1] > x) {
            v[j] = v[j - 1];
            j = j - 1;
        }
        v[j] = x;
    }
}
