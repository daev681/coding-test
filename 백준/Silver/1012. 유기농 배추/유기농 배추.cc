#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void dfs(vector<vector<int>>& field, int i , int j) {

    if (i < 0 || i >= field.size() || j < 0 || j >= field[0].size() || field[i][j] == 0) {
        return;
    }
    // 현재 위치를 확인했음을 표시
    field[i][j] = 0;



    dfs(field, i - 1, j);
    dfs(field, i + 1, j);
    dfs(field, i, j - 1);
    dfs(field, i, j + 1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    vector<int> answer;

    
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k; // m x n  , 갯수
        vector<bool> vistied(m * n, false);
        vector<vector<int>> field(m, vector<int>(n, 0));
        int count = 0;
        while (k--) {
            int f, s;
            cin >> f >> s;
            field[f][s] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (field[i][j] == 1) {
                    ++count;
                    dfs(field, i, j);
                }
            }
        }
        answer.push_back(count);

    }


    for (int& v : answer) {
        cout << v << "\n";
    }
   



    return 0;
}