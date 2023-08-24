#include<bits/stdc++.h>
using namespace std;

const int N = 1105; // Maximum number of nodes
vector<int> adj[N];
int visited[N];

void dfs(int u, int& component_size) {
    visited[u] = 1;
    component_size++;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, component_size);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int u, v;
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> component_sizes; // Store sizes of components
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            int component_size = 0;
            dfs(i, component_size);
            if (component_size > 1) {
                component_sizes.push_back(component_size);
            }
        }
    }
    
    sort(component_sizes.begin(), component_sizes.end());
    
    for (int size : component_sizes) {
        cout << size << " ";
    }

    return 0;
}
