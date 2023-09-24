#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        for (int j =1; j <=n; j++)
        {
            if(i ==1 || i ==n || j == 1 || j ==n)
            {
                if(i == n)
                {
                    cout<<n;
                }
                else if( j== 1)
                {
                    cout<<i;
                }
                else
                {
                    cout<<j;
                }
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
        
    }
    
    return 0;
}
