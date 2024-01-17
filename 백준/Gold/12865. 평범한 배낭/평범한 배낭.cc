#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // pair를 사용하기 위한 헤더
using namespace std;



// worst 
//int main(void) {
//    int n, k , answer = 0;
//    // n 갯수 , k= 버틸수 있는 무게
//    cin >> n >> k;
//    vector<pair<int, int>> vp;
//    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//
//
//    for (int i = 0; i < n; i++) {
//        int w, v;    cin >> w >> v; // w 무게 , v 물건의 가치
//        vp.push_back(make_pair(w,v));
//    }
//
//    for (int i = 0; i < vp.size(); i++) {
//        int w_origin = vp[i].first;
//        int v_origin = vp[i].second;
//        for (int j = i; j < vp.size(); j++) {
//
//            int w_target = vp[j].first;
//            int v_target = vp[j].second;
//            if (k >= w_origin + w_target && answer <= v_origin + v_target ) {
//                answer = v_origin + v_target;
//            }
//        }
//    }
//
//    cout << answer << endl;
//
//    return 0;
//
//
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> items(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    for (int i = 1; i <= n; ++i) {
        int w = items[i].first;
        int v = items[i].second;

        for (int j = 1; j <= k; ++j) {
            if (j >= w) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}