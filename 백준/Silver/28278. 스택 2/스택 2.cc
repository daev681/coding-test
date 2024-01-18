#include <iostream>
#include <queue>
#include <stack>
using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    stack<int> s;
    vector<int> v; 

    while (t--) {
        int command; cin >> command;
        if (command == 1) {
            int data; cin >> data;
            s.push(data);
        }else if (command == 2) {
            if (!s.empty()) {
                v.push_back(s.top());
                s.pop();
            }
            else {
                v.push_back(-1);
            }
        }else if (command == 3) {
            v.push_back(s.size());
        }else if (command == 4) {
            v.push_back(s.empty() ? 1 : 0);
        }else if (command == 5) {
            if (!s.empty()) {
                 v.push_back(s.top());

            }
            else {
                v.push_back(-1);
            }
        }

    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}