#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& field, vector<vector<bool>>& visited, int n, int m) {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });  
    visited[0][0] = true;


    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

  
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

           
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                field[nx][ny] = field[x][y] + 1; 
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    
    vector<vector<int>> field(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cell;
            cin >> cell;
            field[i][j] = cell - '0';  
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));


    bfs(field, visited, n, m);

    cout << field[n - 1][m - 1] << endl;

    return 0;
}