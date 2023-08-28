#include<bits/stdc++.h>
using namespace std;

const int N = 101; // Maximum number of vertices
const int INF = 1e9; // Infinity value for uninitialized distances
int d[N][N]; // Distance matrix

int main() {
    int n;
    cin >> n;

    // Read the weighted matrix input
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            if (d[i][j] == -1) {
                d[i][j] = INF; // Convert -1 to infinity for the Floyd-Warshall algorithm
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    int mx = 0;
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                
            }
        }
    }

    // int mx = 0;

    // Find the maximum shortest distance among all pairs of vertices
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] > mx) 
                {
                    mx = d[i][j];
                }
        }
    }

    cout << mx << "\n";

    return 0;
}
