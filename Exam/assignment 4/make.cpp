#include <bits/stdc++.h>
using namespace std;
int dp[100005];
bool knapsack(int s, int n) {
    if (s == n) {
        return true;
    }
    
    if (s > n) {
        return false;
    }
    if(dp[s] != -1)
    {
        return dp[s];
    }
    bool opt1 = knapsack(s * 10, n);
    bool opt2 = knapsack(s * 20, n);
    return dp[s] = opt1 || opt2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            dp[i]=-1;
        }
        
        if (knapsack(1, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
