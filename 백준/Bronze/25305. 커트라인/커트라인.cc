#include <iostream>
#include <vector>
#include <algorithm>  // std::sort를 사용하기 위해 필요한 헤더
using namespace std;



int main() {
    int  n , m;
    std::cin >> n >> m;
    vector<int> v;

    while (n--) {
        int k;
        std::cin >> k;
        v.push_back(k);
    }

    std::sort(v.begin(), v.end() , std::greater<int>());
    
    
   
    cout << v[m-1] << "\n";


    return 0;
}