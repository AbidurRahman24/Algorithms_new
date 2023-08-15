#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 1e3+5;
const int INF = INT_MAX;
vector<pii>g[N];
vector<int>dist(N,INF);
vector<bool> visited(N);

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    dist[s]=0;
    pq.push({dist[s], s});

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
                pq.push({dist[v],v});
            }
        }
    }


}

int main()
{
    int n,m,u,v,w,a,b;
    cin>>n>>m;
    while (m--) 
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    cin>>a>>b;
    cin>>a>>b;
    dijkstra(a);
    cout<<dist[b]<<endl;
    return 0;
}