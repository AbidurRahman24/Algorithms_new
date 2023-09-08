#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(long long i = 0; i< t; i++)
    {
        int n;
        cin>>n;
        long long s = 0;
        long long a[n];
        for (long long i = 0; i < n; i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        if(s % 2 == 0 && s <= 2000)
        {
            long long sum = s / 2;
            bool dp[n+1][sum+1];
            dp[0][0] = true;
            for (long long i = 0; i < sum; i++)
            {
                dp[0][i] = false;
            }

            for (long long i = 0; i <= n; i++)
            {
                for (long long j = 0; j <=sum; j++)
                {
                    if(a[i-1] <= j)
                    {
                        dp[i][j] = dp[i-1][j - a[i-1]] || dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
                
            }
            if(dp[n][sum]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    
    
    return 0;
}