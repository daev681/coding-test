#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;

void dfs(int i, int j, vector<vector<int>>& graph, vector<vector<bool>>& visited, int& count) {
    int rows = graph.size();
    int cols = graph[0].size();

    if (i < 0 || i >= rows || j < 0 || j >= cols || graph[i][j] == 0 || visited[i][j]) {
        return;
    }

    visited[i][j] = true;
    count++;

    // 이동 방향: 상, 하, 좌, 우
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        dfs(ni, nj, graph, visited, count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> houseCounts;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            graph[i][j] = s[j] - '0';
        }
    }

    int totalComplex = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                int count = 0;
                dfs(i, j, graph, visited, count);
                totalComplex++;
                houseCounts.push_back(count);
            }
        }
    }

    cout << totalComplex << endl;
    sort(houseCounts.begin(), houseCounts.end());
    for (int count : houseCounts) {
        cout << count << endl;
    }

    return 0;
}