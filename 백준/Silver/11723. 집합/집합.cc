#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    int S = 0; // 비트마스크로 집합 표현 (최대 20비트)
    string cmd;
    int x;

    while (m--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1));
        }
        else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1));
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << '\n';
        }
        else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if (cmd == "all") {
            S = (1 << 20) - 1;  // 20개의 비트를 모두 1로
        }
        else if (cmd == "empty") {
            S = 0;
        }
    }

    return 0;
}
