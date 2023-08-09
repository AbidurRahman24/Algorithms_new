#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    level[s]= 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v]= true;
            level[v]=level[u]+1;
        }
    }
    
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
    bfs(1);
    int c;
    cin>>c;
    cout << "Level of " << c << " = " << level[c] << endl;
    // for (int i = 1; i <=n; i++)
    // {
    //     cout<<i<<" "<<level[i]<<endl;
    // }
    
    return 0;
}