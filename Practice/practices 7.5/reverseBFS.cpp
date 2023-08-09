#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> adj[N];
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
        // cout<<u<<" ";
        for(int v:adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
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
    stack<int> st;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])
            st.push(i);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}