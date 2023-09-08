#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        long long s = 0;
        vector<long long> a(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            s += a[j];
        }
        if (s % 2 == 0 && s <= 2000) 
        {
            long long sum = s / 2;
            bool dp[n + 1][sum + 1];
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= sum; j++)
                {
                    if (i == 0)
                        dp[i][j] = false;
                    else if (j == 0)
                        dp[i][j] = true;
                    else if (a[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            if (dp[n][sum])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
