#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
bool visited[N]; 
int list[N];
void dfs(int u)
{
    visited[u] = true;
    // cout<<"visited Node: "<<u<<endl;
    for(int v:adj[u])
    {
        if(visited[v]== true) continue;
        dfs(v);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>v>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for(int i=1; i<=n;i++)
    {
        if(visited[i]) continue;
        dfs(i);
        // cout<<adj[i]<<" "<<endl;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}