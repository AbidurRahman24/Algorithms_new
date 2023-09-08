#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];

bool subset_sum(int n, int s, int a[])
{
    if(n==0)
    {
        if(s==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if(a[n-1] <= s)
    {
        bool opt1 = subset_sum(n-1, s - a[n-1], a);
        bool opt2 = subset_sum(n-1, s, a);
        return dp[n][s] = opt1 || opt2;
    }
    else
    {
        return dp[n][s] = subset_sum(n-1, s, a);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        int s = 1000 - target;
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }

        if (subset_sum(n, s, a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
