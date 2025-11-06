#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // n ints in sorted order (array)
    // q queries
    // in each query, tell whether n[i] is present or not
    // if yes, print "Yes" + index
    // if not, tell the index of the smallest int
    // that is just greater than the queried number

    int n; std::cin >> n;
    std::vector<int> vec(n);

    for (int inx {0}; inx < n; inx += 1) {
        std::cin >> vec[inx];
    }

    int q; std::cin >> q; // queries cnt

    for (int inc {0}; inc < q; inc += 1) {
       int queryInt;
       std::cin >> queryInt;

       std::vector<int>::iterator itr {std::lower_bound(vec.begin(), vec.end(), queryInt)};

       (itr != vec.end() && *itr == queryInt) ? std::cout << "Yes " << (itr - vec.begin() + 1) << endl 
                                              : std::cout <<  "No " << (itr - vec.begin() + 1) << endl;
    }   
    return 0;
}
