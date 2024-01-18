#include <iostream>
#include <stack>
#include <vector>
#include <string>  // <string> 헤더 추가
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const char sopen = '(';
    const char sclose = ')';
    const char lopen = '[';
    const char lclose = ']';

    vector<string> v;
    string str_data;


    while (true) {
        getline(cin, str_data); 

        // 입력이 "."이면 종료
        if (str_data == ".") {
            break;
        }

     
        stack<char> s;
        bool isVaild = true;

        for (int i = 0; i < str_data.size(); i++) {
            char current = str_data[i];

            if (current == sopen || current == lopen) {
                s.push(current);
            }
            else if (current == sclose || current == lclose) {
                if (!s.empty()) {
                    char top = s.top();
                    if ((current == sclose && top == sopen) || (current == lclose && top == lopen)) {
                        s.pop();
                    }
                    else {
                        isVaild = false;
                        break;
                    }
                }
                else {
                    isVaild = false;
                    break;
                }
            }
        }

        if (isVaild && s.empty()) {
            v.push_back("yes");
        }
        else {
            v.push_back("no");
        }
    }

    // 결과 출력
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}