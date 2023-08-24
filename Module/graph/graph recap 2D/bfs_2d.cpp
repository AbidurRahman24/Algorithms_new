#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
int n,m;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pi>q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] =0;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pi child = path[i];
            int ci = pI + child.first;
            int cj = pJ + child.second;
            if(isValid(ci,cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push({ci,cj});
                dis[ci][cj] = dis[pI][pJ] + 1;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            cin>>a[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}