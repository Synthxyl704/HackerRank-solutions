#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N; std::cin >> N;
    std::vector<int> vec(N);
    
    for (int inx {0}; inx < N; inx += 1) {
        std::cin >> vec[inx];
    }
    
    // 2 queries
    int qry1; std::cin >> qry1;
    vec.erase(vec.begin() + (--(qry1)));
    
    // std::cout << (vec.size()) << std::endl;
    
    int qry2[2];
    for (int inx {0}; inx < 2; inx += 1) {
        std::cin >> qry2[inx];
        // q[0] = provenance delimiter
        // q[1] = terminator delimiter
    }
    
    vec.erase((vec.begin() + (--(qry2[0]))), (vec.begin() 
                          + (--(qry2[1]))));
    
    std::cout << vec.size() << std::endl;
    
    for (int inx : vec) {
        std::cout << inx << " ";
    }
    return 0;
}
