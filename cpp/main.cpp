#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include "../sort.hpp"

using namespace std;


void printVector(vector<int> v) {
    for(int val:v) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;
}
   

int main(int argc, char* argv[]) {

    int n = atoi(*(argv+1));          //taille du vector 
    int t = atoi(*(argv+2));          //type du vector ((1) random, (2) half sorted, (3) half reversed)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> global_range(0, 1024 * n);
    uniform_int_distribution<int> r(0, 1023);

    std::vector<int> v(n);
    
    for (int i = 0; i < n; ++i) {
        if (i < n / 2) {                         //première moitié du vector
            if(t == 1) {   
                v[i] = global_range(gen);        //random
            }

            else if(t == 2) {
                v[i] = 1024 * i + r(gen);        //half sorted
            }

            else if(t == 3){
                v[i] = 1024 * (n - i) + r(gen);  //half reversed
            }

        } else {
            v[i] = global_range(gen);            //seconde moitié
        }
    }

    chrono::steady_clock::time_point start_timer = chrono::steady_clock::now();
    sort_algorithm(v); 
    chrono::steady_clock::time_point end_timer = chrono::steady_clock::now();
    size_t duration = chrono::duration_cast<chrono::microseconds>(end_timer - start_timer).count();             //calcul du temps d'execution en millisecondes
    cout << n << " " << duration << endl;

    return 0;
}
