#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int answer = 0;

void dfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[vertex] = true;

    for (int i = 0; i < graph[vertex].size(); i++) {
        int adjacentVertex = graph[vertex][i];
        if (!visited[adjacentVertex]) {
            dfs(adjacentVertex, graph, visited);
        }
    }
}

void dfs_stack(int vertex, vector<vector<int>>& graph, vector<bool>& visited) {
    
    stack<int> s;
    visited[vertex] = true;
    s.push(vertex);

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                answer++;
                visited[v] = true;
                s.push(v);
            }

        }
    }

}



void bfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;

    visited[vertex] = true;
    q.push(vertex);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
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

    dfs_stack(1, graph, visited);




    cout << answer << "\n";


    return 0;
}