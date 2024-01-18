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
        
        if (command == 0) {

            if (!s.empty()) {
                s.pop();
            }
        }
        else {
            s.push(command);
        }

    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }


    cout << sum << "\n";
    return 0;
}