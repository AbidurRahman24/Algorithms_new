#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
// vector<int> adj[N];
vector<pair<int,int>>adj[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int v,u,w;
        cin>>v>>u>>w;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }
    // print
    for (int i = 1; i <=n; i++)
    {
        cout<<"List "<<i<<": ";
        for (auto j:adj[i])
        {
            cout<<"("<<j.first;
            cout<<","<<j.second<<"),";
        }
        cout<<endl;
    }
    
    return 0;
}