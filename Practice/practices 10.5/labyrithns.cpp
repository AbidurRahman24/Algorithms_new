#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N= 1e3+5;
vector<string>g;
bool visited[N][N];
int level[N][N];
pii parent[N][N];
int m,n;
vector<pii> direc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isValid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(int si, int sj) {
    queue<pii> q;              // Queue for BFS traversal
    q.push({si, sj});          // Push the starting cell
    visited[si][sj] = true;    // Mark the starting cell as visited
    level[si][sj] = 0;         // The starting cell is at level 0

    while (!q.empty()) {
        pii upair = q.front();  // Get the front cell from the queue
        int i = upair.first;    // Current cell's row index
        int j = upair.second;   // Current cell's column index
        q.pop();                // Remove the front cell from the queue

        for (auto d : direc) {
            int ni = i + d.first; // New row index after moving in a direction
            int nj = j + d.second; // New column index after moving in a direction

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj]!='x') {
                q.push({ni, nj});    // Push the new cell into the queue
                visited[ni][nj] = true; // Mark the new cell as visited
                level[ni][nj] = level[i][j] + 1; // Set the level of the new cell
                parent[ni][nj] = {i, j}; // Set the parent of the new cell
            }
        }
    }
}

int main()
{
    int si, sj, di,dj;
    cin>>n>>m;
    for(int i=0; i<n;i++)
    {
        string x;
        cin>>x;
        for(int j=0; j<m; j++)
        {
            if(x[j] == 's')
            {
                si=i, sj=j;
            }
            if(x[j]=='e')
            {
                di=i, dj=j;
            }
        }
        g.push_back(x);
    }
    bfs(si,sj);

    if(level[di][dj]!=0)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}