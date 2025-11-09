#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    // std::set<int> setArr;
    // setArr.size()
    // setArr.insert(<enter_int_her>)
    // setArr.erase(<enter_int_to_delete_here>)
    // set<int>::iterator itr = s.find(val); // gives itr pointing to val
    
    // 1 [x] - set.insert(x);
    // 2 [x] - set.erase(x);
    // 3 [x] - Yes if there, No if not
    
    std::set<int> setArr;
    int queryCount; std::cin >> queryCount;
    
    for (int inx {1}; inx <= queryCount; inx += 1) {
        int y; int x;
        std::cin >> y;
        std::cin >> x;
        
        switch (y) {
            case 1:
                setArr.insert(x);
                break;
                
            case 2:
                setArr.erase(x);
                break;
                
            case 3:
                std::set<int>::iterator ITX {setArr.find((x))}; 
                
                (ITX == setArr.end()) 
                ? std::cout << "No" << std::endl                      
                : std::cout << "Yes" << std::endl;
                break;
        }
    }
    
    return 0;
}
