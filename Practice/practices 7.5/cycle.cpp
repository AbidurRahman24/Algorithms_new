#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
bool dfs(int u, int p=-1)
{
    bool cycleExist = false;
    visited[u] = true;
    for(int v:adj[u])
    {
        if(v==p) continue;
        if(visited[v]) return true;
        cycleExist = cycleExist || dfs(v);
    }
    return cycleExist;
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int v,u;
        cin>>v>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isCycle = false;
    for(int i=1; i<=n; i++)
    {
        if(visited[i]) continue;
        isCycle = isCycle || dfs(i);
    }

    if(isCycle)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}