#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    int k;
    cin >> k;
    
    int d = adj[k].size(); 

    cout << d << endl;

    return 0;
}
