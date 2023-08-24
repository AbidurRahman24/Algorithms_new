#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
int visited[N];
int level[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    level[s] = 0;  
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (visited[v]) continue;
            q.push(v);
            visited[v] = 1;
            level[v] = level[u] + 1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int v, u;
        cin >> v >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c;
    cin >> c;
    bfs(0);
    
    vector<int> l;
    for (int i = 0; i < N; i++) {
        if (level[i] == c) {
            l.push_back(i);
        }
    }
    
    if (l.empty()) {
        cout << -1 << endl;
    } else {
        for (int v : l) {
            cout << v << " ";
        }
    }

    return 0;
}
