#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector <int> adj[N];

int main()
{
    int n;
    cin >> n;
    int matrix[n][n];
    
    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Convert adjacency matrix to adjacency list
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] == 1) {
                adj[i].push_back(j);
            }
        }
    }
    
    // Print adjacency list
    for (int i = 1; i <= n; i++) {
        cout << "List " << i << " : ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}