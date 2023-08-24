#include<bits/stdc++.h>
using namespace std;

const int N = 1005; // Assuming the maximum number of nodes is 1000
vector<int> adj[N];
bool visited[N];

void bfs(int s, vector<int>& current_cc) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        current_cc.push_back(u);
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
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
    
    vector<int> component_sizes;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> current_cc;
            bfs(i, current_cc);
            component_sizes.push_back(current_cc.size());
        }
    }
    
    sort(component_sizes.begin(), component_sizes.end());
    
    for (int size : component_sizes) {
        cout << size << " ";
    }
    
    return 0;
}