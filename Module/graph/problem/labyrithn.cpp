#include<bits/stdc++.h>
using namespace std;
/*----Header Part Start-----*/
typedef pair<int,int> pii;
const int N = 1e3+5;
vector<string> g;           // Store the grid/map as a vector of strings
bool visited[N][N];         // Matrix to keep track of visited cells
int level[N][N];            // Matrix to store the level of each cell from the starting cell
pii parent[N][N];           // Matrix to store the parent of each cell (used to reconstruct the path)
int n, m;                   // Dimensions of the grid
vector<pii> direc{{0,-1},{0,1},{-1,0},{1,0}}; // Possible directions: left, right, up, down

/*----Header Part end -----*/

// valid check
bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);  // Check if a cell is within the grid boundaries
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

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj]) {
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
    // input part
    int si,sj,di,dj;
    cin>>n>>m;
    for(int i=0; i<n;i++)
    {
        string x;
        cin>>x;
        for(int j=0; j<m; j++)
        {
            if(x[j] == 'A')
            {
                si=i, sj=j;
            }
            if(x[j]=='B')
            {
                di=i, dj=j;
            }
        }
        g.push_back(x);
    }
    bfs(si,sj);
    if(level[di][dj]!=0)
    {
        cout<<"Yes"<<endl;
        cout<<level[di][dj]<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    vector<pii> path;
    pii cur = {di,dj};
    while(!(cur.first == si && cur.second ==sj))
    {
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    path.push_back({si,sj});
    reverse(path.begin(), path.end());
    for(int i=1; i<path.size(); i++)
    {
        if(path[i-1].first == path[i].first)
        {
            if(path[i-1].second == path[i].second-1)
            {
                cout<<"R";
            }
            else
            {
                cout<<"L";
            }
        }
        else
        {
            if(path[i-1].first == path[i].first-1)
            {
                cout<<"D";
            }
            else
            {
                cout<<"U";
            }
        }
    }
    return 0;
}