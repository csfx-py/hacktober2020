vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices
int m; // number of edges
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

int main () {
    cin >> n >> m;
    adj.resize (n);
    visited.assign(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i);
    }
    return 0;
}
