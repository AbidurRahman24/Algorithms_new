#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int pos = -1;
        int pos2 = -1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > mx1)
            {
                mx2 = mx1;
                mx1 = a[i];
                
                pos = i;
            }
            else if (a[i] > mx2 && a[i] != mx1)
            {
                mx2 = a[i];
                pos2 = i;
            }
        }
        
        cout << pos << " " << pos2 << endl;
    // }

    return 0;
}