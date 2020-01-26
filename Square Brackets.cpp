#include <bits/stdc++.h>
using namespace std;
int square_brackets(int n,int o,int c,map<int,int> m,int **dp){
    if(o>n || c>n) return 0;
    if(o==n && c==n) return 1;
     if(dp[o][c]>-1) return dp[o][c];
     
    if(o==c || m[o+c]==1) {
         dp[o][c]=square_brackets(n,o+1,c,m,dp);
        return dp[o][c];
    }
       
    else if(o==n){
         dp[o][c]=square_brackets(n,o,c+1,m,dp);
        return dp[o][c];
    }
    else{
        dp[o][c]=(square_brackets(n,o+1,c,m,dp)+square_brackets(n,o,c+1,m,dp));
        return dp[o][c];
    } 
        
}
int main()
{
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>k;
        int *arr=new int[k];
        map<int,int> m;
        for(int i=0;i<k;i++){
            cin>>arr[i];
            m[arr[i]-1]=1;
        }
        int **dp=new int*[n+1];
        for(int i=0;i<=n;i++){
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
       cout<<square_brackets(n,0,0,m,dp)<<endl; 
        m.clear();
        for(int i=0;i<=n;i++)
             delete []dp[i];
        delete []arr;
        delete []dp;
 }
    return 0;
}
