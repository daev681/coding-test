
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n; 
    vector<int> t(n); 


    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end(), greater<int>());

    int max_day = 0; 
    for (int i = 0; i < n; i++) {
          int day = (i + 1) + t[i] + 1 ;  
        max_day = max(max_day, day); 
    }

    cout << max_day << endl; 
    return 0;
}