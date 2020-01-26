#include <bits/stdc++.h>
using namespace std;
int find_profit(int *stock,int n,int k,int r_transaction,int ***dp){
    if(n==0 || k<=0)
        return 0;
     if(dp[n][k][r_transaction]>-1)
         return dp[n][k][r_transaction];
    int option1=find_profit(stock+1,n-1,k,r_transaction,dp);
    int option2=0;
    if(r_transaction==1)
     option2=find_profit(stock+1,n-1,k-1,0,dp)+stock[0];
    int option3=0;
    if(k>0)
        option3=find_profit(stock+1,n-1,k,1,dp)-stock[0];
    int ans=max(option1,max(option2,option3));
    dp[n][k][r_transaction]=ans;
    return ans;
}
int main()
{
    int t,k,n;
    cin>>t;
    while(t--){
        cin>>k>>n;
        int *stock=new int[n];
        for(int i=0;i<n;i++)
            cin>>stock[i];
        int ***dp=new int**[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int*[k+1];
            for(int j=0;j<=k;j++){
                 dp[i][j]=new int[2];
                  for(int m=0;m<2;m++){
                      dp[i][j][m]=-1;
                  }
            }     
        }
        cout<<find_profit(stock,n,k,0,dp)<<endl;
    }
    return 0;
}
