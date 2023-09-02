#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<long long>> dis(n + 1, vector<long long>(n + 1, INF));

    // Initialize the distance matrix
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }

    // Input the edges and their weights
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b], w);
    }

    // Floyd-Warshall algorithm to compute minimum distances
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;

    // Answer the queries
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        // If there is no connection between x and y, print -1
        if (dis[x][y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[x][y] << endl;
        }
    }

    return 0;
}
