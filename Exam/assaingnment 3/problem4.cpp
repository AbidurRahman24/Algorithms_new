#include <bits/stdc++.h>
using namespace std;

class Edge 
{
public:
    int u;
    int v;
    long long w; 
    Edge(int u, int v, long long w) 
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--) 
    {
        int a, b;
        long long w; // Use long long for weights
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    int s;
    cin >> s;

    int t;
    cin >> t;

    while (t--) 
    {
        int d;
        cin >> d;

        vector<long long> dis(n + 1, 1e18 + 5); 
        dis[s] = 0;

        for (int i = 1; i <= n - 1; i++) 
        {
            for (int j = 0; j < v.size(); j++) 
            {
                Edge ed = v[j];
                int a = ed.u;
                int b = ed.v;
                long long w = ed.w;
                if (dis[a] != 1e18 + 5 && dis[a] + w < dis[b]) 
                {
                    dis[b] = dis[a] + w;
                }
            }
        }

        bool cycle = false;
        for (int j = 0; j < v.size(); j++) 
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            long long w = ed.w;
            if (dis[a] != 1e18 + 5 && dis[a] + w < dis[b]) 
            {
                cycle = true;
                break;
            }
        }

        if (cycle) 
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        } else 
        {
            if (dis[d] == 1e18 + 5) 
            {
                cout << "Not Possible" << endl;
            } else 
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}
