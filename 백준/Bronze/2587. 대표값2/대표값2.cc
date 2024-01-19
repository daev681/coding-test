#include <iostream>
#include <vector>
#include <algorithm>  // std::sort를 사용하기 위해 필요한 헤더
using namespace std;



int main() {
    int  n = 5;
        
        //   std::cin >> n;
    vector<int> v;

    while (n--) {
        int k;
        std::cin >> k;
        v.push_back(k);
    }

    std::sort(v.begin(), v.end());
    
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    int arg = sum / v.size();
    int mid = v[v.size() / 2];

    cout << arg << "\n" << mid;


    return 0;
}