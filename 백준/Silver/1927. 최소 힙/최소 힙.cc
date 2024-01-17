#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    vector<int> v; 


    while (t--) {
        int data;
        cin >> data;
        if (data == 0 && !min_heap.empty()) {
            v.push_back(min_heap.top());
            min_heap.pop();
        }
        else if (data == 0) {
            v.push_back(0);
        }
        else {
            min_heap.push(data);
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
     
       

    return 0;
}