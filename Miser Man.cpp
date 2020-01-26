#include <bits/stdc++.h>
using namespace std;
int miser_man(int **grid,int i,int j,int n,int m,int **dp){
    if(i==n || j==m ||j<0)
        return INT_MAX;    
    if(dp[i][j]>-1)
        return dp[i][j];
    for(int )     
     int ans=grid[i][j]+min(miser_man(grid,i+1,j-1,n,m,dp)
                           ,min(miser_man(grid,i+1,j,n,m,dp),miser_man(grid,i+1,j+1,n,m,dp)));
    dp[i][j]=ans;
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **grid=new int*[n];
    int **dp=new int*[n];
    for(int i=0;i<n;i++){
        grid[i]=new int[m];
        dp[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
          dp[i][j]=-1;
        }
    }
    cout<<miser_man(grid,0,0,n,m,dp)<<endl;
    int min_c=dp[0][0];
    for(int i=1;i<n;i++)
        min_c=min(min_c,dp[0][i]);
    for(int i=0;i<n;i++){
        delete []grid[i];
        delete []dp[i];
    }
    delete []grid;
    delete []dp;  
    cout<<min_c;
    return 0;
}
