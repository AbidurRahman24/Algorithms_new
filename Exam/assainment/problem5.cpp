#include<bits/stdc++.h>
using namespace std;
void solve(int arr1[], int arr2[], int n, int m, int result[])
{
    int i=0; 
    int j= 0;
    int k= 0;
    // marge two array both have element;
    while(i<n && j<m)
    {
        if(arr1[i] > arr2[j])
        {
            result[k++] = arr1[i++];
        }
        else
        {
            result[k++] = arr2[j++];
        }
    }

    // if there are remaining element in array1 or array2. Add the marged array;
    while(i<n)
    {
        result[k++] = arr1[i++];
    }
    while(j<m)
    {
        result[k++] = arr2[j++];
    }
}

int main()
{
    int n,m;
    cin>>n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    cin>>m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin>>arr2[i];
    }
    int result[m+n];

    solve(arr1, arr2, m,m,result);
    
    for(int i=0; i<(n+m);i++)
    {
    	cout << result[i] << " ";
    }
    return 0;
}