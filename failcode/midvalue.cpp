#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> max_heap; 
    priority_queue<int, vector<int>, greater<int>> min_heap; 

    vector<double> answer;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        if (max_heap.empty() && min_heap.empty()) {
            max_heap.push(k);
            answer.push_back(k);
        }
        else {
          
            if (k <= max_heap.top()) {
                max_heap.push(k);
            }
            else {
                min_heap.push(k);
            }

       
            while (max_heap.size() > min_heap.size() + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }

            while (min_heap.size() > max_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }

       
            int mid;
            if (max_heap.size() == min_heap.size()) {
                mid = max_heap.top();
            }
            else {
                mid = max_heap.top();
            }

            answer.push_back(mid);

        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}
