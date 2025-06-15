#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;

    vector<int> kits(n);
    for (int i = 0; i < n; ++i) cin >> kits[i];

    vector<int> index(n);
    for (int i = 0; i < n; ++i) index[i] = i; // 인덱스 0 ~ n-1

    do {
        int weight = 500;
        bool valid = true;

        for (int i = 0; i < n; ++i) {
            weight += kits[index[i]];
            weight -= k;

            if (weight < 500) {
                valid = false;
                break;
            }
        }

        if (valid) cnt++;
    } while (next_permutation(index.begin(), index.end()));

    cout << cnt << '\n';
    return 0;
}
