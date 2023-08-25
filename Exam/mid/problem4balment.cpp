#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+7;
const int INF = 1e9+7;
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
long long int dis[N];
int n,m;

void bellman_ford(int s)
{
	for(int i=1;i<=n;i++)
		dis[i] = INF;

	dis[s] = 0;

	for(int i=1;i<n;i++)
	{
		//all edges relaxation
		for(int u=1;u<=n;u++)
		{
			for(pii vpair: g[u])
			{
				int v = vpair.first;
				int w = vpair.second;

				if(dis[u]!=INF && dis[v] > dis[u]+w)
				{
					dis[v] = dis[u]+w;
				}
			}
		}
	}
}

int main()
{
    
    cin >> n >> m;

    while(m--)
    {
    	int u,v,w;
    	cin >> u >> v >> w;
    	g[u].push_back({v,w});
    }
for (int i = 1; i <= n; i++)
    {
        dis[i] = LONG_MAX;
    }
    // bellman_ford(1);
    int s;
    cin>>s;
    bellman_ford(s);
    int t;
    cin>>t;
    while (t--)
    {
        int d,dw;
        cin>>d>>dw;
        if(dis[d] <= dw)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}