#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,target;
        cin>>n>>target;
        int s = 1000-target;
        int a[n];
        int dp[n+1][s+1];
        for (int i = 0; i <=n; i++)
        {
            for (int j = 0; j <=s; j++)
            {
                if(i==0 || j== 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <=s; j++)
            {
                if(a[i-1] <= j)
                {
                    dp[i][j] = max(a[i-1] + dp[i][j-a[i-1]], dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    if(dp[n][s] == s)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}