#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adjList[N];
bool visited[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<"visiting "<<u<<endl;
        for(int v:adjList[u])
        {
            // section 2: child proccessed
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]= true;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bfs(1);
    
    return 0;
}