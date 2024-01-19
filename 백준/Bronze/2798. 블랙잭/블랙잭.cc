#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main() {
    vector<int> answer;
    vector<int> v;

    int n, m; cin >> n >> m;


    while (n--) {
        
        int card; cin >> card;
        v.push_back(card);
    }
    int closest_sum = 0;

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                int current_sum = v[i] + v[j] + v[k];
                if (current_sum <= m && current_sum > closest_sum) {
                    closest_sum = current_sum;
                    answer = { v[i], v[j], v[k] };
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < answer.size(); i++) {
        sum += answer[i];
    }

    cout << sum;

   


    return 0;
}