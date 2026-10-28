#include "../sort.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void sort_algorithm(vector<int> &v) {
    stable_sort(v.begin(), v.end());
}