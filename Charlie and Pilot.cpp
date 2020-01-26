#include <bits/stdc++.h>
using namespace std;
int charlie_pilots(int *a,int n,int x,int *c,int **dp){
    if(n==0)
        return 0;
    if(dp[n][x]>-1)
        return dp[n][x];
    int option1=INT_MAX;
    int option2=INT_MAX;
    int option3=INT_MAX;
    int option4=INT_MAX;
    if(x==0)
        option1=a[0]+charlie_pilots(a+1,n-1,x+1,c+1,dp);
    else if(x==n)
        option2=c[0]+charlie_pilots(a+1,n-1,x-1,c+1,dp);
    else{
        option3=a[0]+charlie_pilots(a+1,n-1,x+1,c+1,dp);
        option4=c[0]+charlie_pilots(a+1,n-1,x-1,c+1,dp);
    }
    int ans=min(min(option1,option2),min(option3,option4));
    dp[n][x]=ans;
    return ans;
        
}
int main()
{
    int n;
    cin>>n;
    int *c=new int[n];
    int *a=new int[n];
    for(int i=0;i<n;i++)
        cin>>c[i]>>a[i];
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[n];
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }
    int ans=charlie_pilots(a,n,0,c,dp);
    cout<<ans;
    for(int i=0;i<=n;i++)
        delete []dp[i];
    delete []c;
    delete []a;
    delete []dp;
    
    return 0;
}
