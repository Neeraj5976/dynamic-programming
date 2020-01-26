#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
int adjacent_bit_count(int n,int k,int start,int ***dp){
    if(n==1){
        if(k==0)
          return 1;
        return 0;
    }
    if(n==0)
        return 0;
    if(k<0)
        return 0;
    if(dp[n][k][start]>-1)
        return dp[n][k][start];
    int ans1=0;
    int ans2=0;
    int ans=0;
     if(start==1){
         ans1=adjacent_bit_count(n-1,k,0,dp);
         ans2=adjacent_bit_count(n-1,k-1,1,dp);
         
     }
    else{
        ans1=adjacent_bit_count(n-1,k,0,dp);
        ans2=adjacent_bit_count(n-1,k,1,dp);
    }
    ans=(ans1+ans2)%m;
    dp[n][k][start]=ans;
    return ans;
}
int main()
{
  int t,n,k,num;
    cin>>t;
    while(t--){
        cin>>num>>n>>k;
         int ***dp=new int**[n+1];
         for(int i=0;i<=n;i++){
            dp[i]=new int*[k+1];
            for(int j=0;j<=k;j++){
                dp[i][j]=new int[2];
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }
         int ans1=adjacent_bit_count(n,k,0,dp);
        int ans2=adjacent_bit_count(n,k,1,dp);
       
        long ans3=(long)(ans1+ans2);
        int ans=(int)(ans3%m);
        cout<<num<<" "<<ans<<endl;
    }
    return 0;
}
