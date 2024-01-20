#include <iostream>
#include <vector>
#include <algorithm>  // std::sort를 사용하기 위해 필요한 헤더
using namespace std;



int main() {
    int  n;
    std::cin >> n;
    vector<pair<int,int>> vp;
    int div = 10;

    while (n--) {
        int a, b;
        std::cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }

    std::sort(vp.begin(), vp.end());
    
    
    for (auto& p : vp) {
        std::cout << p.first << " " << p.second << "\n";
    }


    return 0;
}