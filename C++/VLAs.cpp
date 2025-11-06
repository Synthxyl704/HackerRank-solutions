#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(void) {
    // a[i]     = [6,9]
    // a[i + 1] = [4,2,0]
    // a[i + 2] = [6,7]
    // [i, j]
    //
    // L1 = [x y] = Num o/VLAs, Queries amount
    // for each index of arr, there is a VLA[k] {
    //      sizeOf_k k[i] k[i + 1] k[i + 2]
    // }
    // arrs.size() = n
    // arrs(n)
    
    // 2 2
    // 2 arrays // 2 queries
    int n, q; // god forbid do not obfuscate code here
    std::cin >> n >> q;
    
    if (n < 1 || n > 10E5) {
        std::exit(1);
    }
    
    std::vector<std::vector<int>> arrs(n);
    
    // arrs[inx][inj] = k[ix]
    // arrs[inx + 1][inj + 1] = k[in + 1]
    // YESSSSSSSSSSSS
    // sizeOf_k l[ix] k[ix + 1] k[ix + 2] ...
    // 3        1         5         4 
    for (int inx {0}; inx < n; inx += 1) {
        int k; 
        std::cin >> k; // size of k
        
        if (k < 1 || k > (3 * 10E5)) {
            std::exit(1);
        }
        
        // arrs[inx].std::vector::resize(k);
        // for every index inx, resize the inx array to (k) elements
        arrs[inx].resize(k);
        for (int inc {0}; inc < k; inc += 1) {
            // 0 -> 1 5 4
            // a[inx]k[inc]
            // a[inx] = 3
            // k[inc] = 1 5 4
            // 3 1 5 4 !!!
            std::cin >> arrs[inx][inc];
        }
    }
    
    for (int inx {0}; inx < q; inx += 1) {
        // 0 1 = 5
        // 1 3 = 9
        // YESSSS
        // they way they word is so cancer...
        
        int i, j;
        std::cin >> i >> j;
        
        if (i < 0 || i > n || j < 0 /* || j > k */) {
            std::exit(1);
        }
        
        std::cout << arrs[i][j] << std::endl;
    }
    return 0;
}
