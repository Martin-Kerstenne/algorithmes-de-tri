#include "../sort.hpp"
#include <vector>
#include <iostream>

using namespace std;

void sort_algorithm(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i <= n - 2; i++) {
        int min = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}