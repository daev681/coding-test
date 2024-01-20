#include <iostream>
#include <vector>
#include <algorithm>  // std::sort를 사용하기 위해 필요한 헤더
using namespace std;

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second;  
    }
    return a.first < b.first;  
}

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

    std::sort(vp.begin(), vp.end(), compare);
    
    
    for (auto& p : vp) {
        std::cout << p.first << " " << p.second << "\n";
    }


    return 0;
}