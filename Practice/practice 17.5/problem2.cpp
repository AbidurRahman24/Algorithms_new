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
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Print the matrix of shortest distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
