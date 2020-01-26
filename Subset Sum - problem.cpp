#include <bits/stdc++.h>
using namespace std;
bool flag=false;
void subset_sum(int *arr,int n,int k,int **dp){
    if(k==0){
      flag=true;
        return;
    }
    if(n==0)
        return;
    if(dp[n][k]>-1)
        return;
    if(k-arr[n-1]>=0)
        subset_sum(arr,n-1,k-arr[n-1],dp);
    subset_sum(arr,n-1,k,dp);
    dp[n][k]=0;
}
int main()
{
    int n,k;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
         dp[i]=new int[k+1];
        for(int j=0;j<=k;j++)
            dp[i][j]=-1;
    }
    subset_sum(arr,n,k,dp);
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
