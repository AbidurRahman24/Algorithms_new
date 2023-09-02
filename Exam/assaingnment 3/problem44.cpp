#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 1e5+7;
const int INF = 1e18+5;
vector<pii> g[N];
// vector<pair<pii, int>> list_of_edges;
int d[N];
int n, m;

bool bellman_ford(int s)
{
    for(int i=1;i<=n;i++)
        d[i] = INF;

    d[s] = 0;

    for(int i=1;i<n;i++)
    {
        for(int u=1;u<=n;u++)
        {
            for(pii vpair: g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (d[u] != INF && d[u] + w < d[v]) 
                {
                    d[v] = d[u] + w;
                }
            }
        }
    }

    for(int u=1;u<=n;u++)
    {
        for(pii vpair: g[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (d[u] != INF && d[u] + w < d[v]) 
            {
                return false; 
            }
        }
    }

    return true;
}

int main()
{

    cin >> n >> m;
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    int s;
    cin>>s;
    int t;
    cin >> t;

    while (t--) {
        int des;
        cin >> s >> des;

        if (bellman_ford(s)) {
            if (d[des] == INF) {
                cout << "Not Possible" << endl;
            } else {
                cout << d[des] << endl;
            }
        } else {
            cout << "Negative Cycle Detected" << endl;
        }
    }

    return 0;
}
