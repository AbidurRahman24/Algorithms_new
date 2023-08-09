#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector <int> adj[N];
bool visited[N];
vector<vector<int>> cc;
vector<int> current_cc;
void dfs(int u)
{
    visited[u] = true;
    current_cc.push_back(u);
    for(int v:adj[u])
    {
        if(visited[v]==true) continue;
        dfs(v);

    }
}
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
        }
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        current_cc.clear();
        dfs(1);
        cc.push_back(current_cc);
    }
    for(auto c_cc: cc)
    {
        for(int v:c_cc)
        {
            cout<<"component : "<<v<<" ";
        }
        cout<<endl;
    }
    // dfs(1);
    // bfs(1);
    return 0;
}