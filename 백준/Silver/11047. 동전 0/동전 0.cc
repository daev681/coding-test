#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n , m;
    cin >> n >> m;

    vector<int> money(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }

    int answer = 0;
    sort(money.begin(), money.end() , greater<int>());

    while (m > 0) {
        for (int i = 0; i < n; i++) {
            if (money[i] <= m) {
                m -= money[i];
                answer++;
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}