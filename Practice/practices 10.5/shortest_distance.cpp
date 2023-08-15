#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
const int INF = 1e9 + 10;
vector<pii> g[N];
vector<int> dist(N, INF);
vector<bool> visited(N);

void dijkstra(int s)
{
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s],s});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(pii vpair:g[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if(visited[v]) continue;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m, w;
    cin >> n >> m ;
    while (m--)
    {
        int u, v;
        cin >> u >> v>> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int a,b;
    cin>>a>>b;
    dijkstra(a);
    cout << dist[b] << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Distance of Node " << i << " : ";
    //     cout << dist[i] << endl;
    // }
    return 0;
}