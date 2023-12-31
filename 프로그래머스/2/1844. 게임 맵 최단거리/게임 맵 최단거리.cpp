#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Point {
    int x, y, distance;
};

int BFS(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<Point> q;
    q.push({0, 0, 1}); // 시작 위치를 큐에 넣음
    visited[0][0] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int distance = current.distance;

        // 목적지에 도착했을 경우 최단 거리를 반환
        if (x == n - 1 && y == m - 1) {
            return distance;
        }

        // 상하좌우 이동
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나거나 벽이거나 이미 방문한 경우 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny] == 0 || visited[nx][ny]) {
                continue;
            }

            // 다음 위치를 큐에 넣음
            q.push({nx, ny, distance + 1});
            visited[nx][ny] = true;
        }
    }

    // 도착하지 못한 경우
    return -1;
}

int solution(vector<vector<int> > maps)
{
  
    int answer = BFS(maps); // DFS 호출
    return answer; // 최단 거리 반환

}