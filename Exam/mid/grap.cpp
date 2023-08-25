#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
int n, m;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}
bool bfs(int si, int sj, int di, int dj)
{
    queue<pi> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        if (pI == di && pJ == dj)
            return true;
        for (int i = 0; i < 4; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ) && !vis[cI][cJ])
            {
                vis[cI][cJ] = true;
                q.push({cI, cJ});
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;

    if (bfs(si, sj, di, dj))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
