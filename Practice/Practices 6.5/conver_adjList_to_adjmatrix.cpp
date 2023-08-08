#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> adj[N];
int adjMatrix[N][N]; // Adjacency matrix
int main()
{
    int n,m;
    cin>>n>>m;
    int u,v;
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    // Convert adjacency list to adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j : adj[i])
        {
            adjMatrix[i][j] = 1;
        }
    }
    // Print adjacency matrix
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}