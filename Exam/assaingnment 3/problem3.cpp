#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int parentLevel[N];

class Edge
{
public:
    int a, b; 
    long long w;
    Edge(int a, int b, long long w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);

    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }

    sort(v.begin(), v.end(), cmp);

    long long total = 0;

    for (Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        long long w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA != leaderB)
        {
            ans.push_back(val);
            dsu_union(a, b);
            total += val.w;
        }
    }

    if (ans.size() == n - 1)
    {
        cout << total << endl;
    }
    else
    {
        cout << -1 << endl;
    }


    return 0;
}
