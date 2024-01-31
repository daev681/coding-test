#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1, 0);  
    vector<int> answer;

  
    for (int i = 1; i <= n; i++) {
        int data; cin >> data;
        v[i] = v[i - 1] + data;
    }


    while (m--) {
        int f, l; cin >> f >> l;
        answer.push_back(v[l] - v[f - 1]); 
    }

  
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}