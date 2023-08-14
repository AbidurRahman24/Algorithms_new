#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>g[N];
vector<bool> visited(N,false);
vector<int> level(N,0);
vector<int> parent(N,-1);


void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]= 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:g[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            parent[v]=u;
            level[v]= level[u]+1;
            // parent=
        }
    }
    
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    cout<<"level : "<<level[n]<<endl;
    vector<int>path;
    int cur = n;
    while(cur!=-1)
    {
        path.push_back(cur);
        cur= parent[cur];
    }
    reverse(path.begin(), path.end());
    for(auto p:path)
    {
        cout<<p<<" ";
    }
    return 0;
}