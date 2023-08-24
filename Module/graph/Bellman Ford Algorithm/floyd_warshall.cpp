#include<bits/stdc++.h>
using namespace std;
// typedef pair<int,int>pii;
const int N = 1e3+7;
const int INF = INT_MAX;
// vector<pii> g[N];
int d[N][N];
int n,m;
void dist_initilize()
{
    // cout<<n<<m<<endl;;

    for (int i =1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(i!=j)
            {
                d[i][j] = INF;
            }
        }
        
    }
    
}
void print_matrix()
{
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if(d[i][j] == INF) cout<< "X"<<" ";
            else cout<<d[i][j]<<" ";
        }
    cout<<endl;
    }
}
void floyd_warshall()
{
    for (int k = 1; k <=n; k++)
    {
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
            
        }
    }
}
int main()
{
    cin>>n>>m;
    dist_initilize();
    while (m--)
    {   
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v] =w;
    }
    // d[1][1] =0;
    print_matrix();
    
    floyd_warshall();
    cout<<"\n Floyd Warshall\n";
    print_matrix();
    return 0;
}