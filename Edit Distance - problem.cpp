#include<iostream>
#include<cstring>
using namespace std;
int lcs1(string s1,string s2,int m,int n,int **dp){
    if(m==0)
        return n;
    if(n==0)
        return m;
    if(dp[m][n]>-1)
        return dp[m][n];
    int ans;
    if(s1[0]==s2[0])
        ans=lcs1(s1.substr(1),s2.substr(1),m-1,n-1,dp);
   else
       ans=1+min(lcs1(s1.substr(1),s2.substr(1),m-1,n-1,dp),min(lcs1(s1.substr(1),s2,m-1,n,dp),lcs1(s1,s2.substr(1),m,n-1,dp)));
    dp[m][n]=ans;
    return ans;
}
int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int m=s1.length();
    int n=s2.length();
   int **dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
         for(int j=0;j<=n;j++)
             dp[i][j]=-1;
    }
   int ans=lcs1(s1,s2,m,n,dp);
    for(int i=0;i<=m;i++)
        delete []dp[i];
    delete []dp;
    return ans;
     
}
