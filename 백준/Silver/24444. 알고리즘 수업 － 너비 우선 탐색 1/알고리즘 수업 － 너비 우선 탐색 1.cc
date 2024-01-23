#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& sequence) {
    static int order = 1;
    visited[vertex] = true;
    sequence[vertex] = order++;

    for (int i = 0; i < graph[vertex].size(); i++) {
        int adjacentVertex = graph[vertex][i];
        if (!visited[adjacentVertex]) {
            dfs(adjacentVertex, graph, visited, sequence);
        }
    }
}

void bfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& sequence) {
    static int order = 1;
    queue<int> q;

    visited[vertex] = true;
    sequence[vertex] = order++;
    q.push(vertex);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                sequence[v] = order++;
                q.push(v);
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;
    const int MAX = n + 1;
    vector<vector<int>> graph(MAX);
    vector<bool> visited(MAX, false);
    vector<int> sequence(MAX);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(r, graph, visited, sequence);

    for (int i = 1; i <= n; i++) {
        cout << sequence[i] << "\n";
    }

    return 0;
}