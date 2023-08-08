#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int height[N];
void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if(visited[v] == true) continue;
        dfs(v);
        height[u] = max(height[u], height[v]+1);
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i = 0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);

    int t;
    cin >> t; // Input the node for which you want to find the depth

    cout << "Depth of node " << t << " = " << height[t] << endl;
    return 0;
}