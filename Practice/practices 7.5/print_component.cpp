#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
vector<vector<int>> cc;
vector<int>current_cc;


void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    current_cc.push_back(s);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                current_cc.push_back(v);
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
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            current_cc.clear();
            bfs(i);
            cc.push_back(current_cc);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    for (int i = 0; i < cc.size(); i++) {
        cout << "Component " << i + 1 << " : ";
        for (int v : cc[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
