#include <iostream>
#include <queue>
#include <stack>
using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const char open = '(';
    const char close = ')';
    int t;
    cin >> t;
    
    vector<string> v; 

    while (t--) {
        stack<char> s;
        string str_data; cin >> str_data;
        bool isVaild = true;
        for (int i = 0; i < str_data.size(); i++) {
            if (str_data[i] == open) {
                s.push(open);
            }
            else {
                if (!s.empty()) {
                    s.pop();
                }
                else {
                    isVaild = false;
                    break;
                }             
            }
        }
        if (isVaild && s.empty()) {
            v.push_back("YES");
        }
        else {
            v.push_back("NO");
        }
      
        
     

    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }


    return 0;
}