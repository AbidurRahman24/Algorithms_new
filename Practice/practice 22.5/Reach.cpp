#include<bits/stdc++.h>
using namespace std;
long long dp[105];
bool reach(long long s, long long n)
{
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
    bool opt1 = reach(s * 10, n);
    bool opt2 = reach(s * 20, n);
    return dp[s] = opt1 || opt2;
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        for (long long i = 0; i < n; i++)
        {
            dp[i] = -1;
        }
        
        if(reach(1,n))
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