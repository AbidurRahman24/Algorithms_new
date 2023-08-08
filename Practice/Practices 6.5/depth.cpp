#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> adj[N];
bool visited[N];
int depth[N];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1); // Start DFS from root node 1
    int t;
    cin >> t; // Input the node for which you want to find the depth

    cout << "Depth of node " << t << " = " << depth[t] << endl;
    // Print the depth of each node
    // for (int i = 1; i <= n; i++) {
    //     cout << "Depth of node " << i << " = " << depth[i] << endl;
    // }

    return 0;
}
