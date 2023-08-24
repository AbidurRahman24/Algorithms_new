#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    bool flag = false;

    int l=0;
    int r= n-1;

    while(l<=r)
    {
        int mid = (l+r) /2;
        if(arr[mid] ==x)
        {
            cout<<arr[mid]<<endl;
            flag= true;
            break;
        }
        if(x>arr[mid])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }

    if(flag==false)
    {
        cout<<"Not Found"<<endl;
    }


    
    return 0;
}