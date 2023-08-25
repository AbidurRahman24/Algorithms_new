#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<pii> direc = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool isValid(int i, int j, int N, int M) {
    return (i >= 0 && i < N && j >= 0 && j < M);
}

void bfs(int si, int sj, int di, int dj, int N, int M) {
    vector<vector<int>> visited(N, vector<int>(M, 0));
    vector<vector<int>> level(N, vector<int>(M, 0));

    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty()) {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direc) {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj, N, M) && !visited[ni][nj]) {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }

    if (visited[di][dj]) {
        cout << level[di][dj] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, si, sj, di, dj;
        cin >> N >> M >> si >> sj >> di >> dj;
        bfs(si, sj, di, dj, N, M);
    }

    return 0;
}
