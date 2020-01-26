int solve1(string S,string V,int **dp){
    if(S.empty())
        return 1000000000; 
    if(V.empty())
        return 1;
    int option1=0;
    if(dp[S.length()][V.length()]>-1)
       return dp[S.length()][V.length()];
     option1+=solve1(S.substr(1),V,dp);
    int index=V.find(S[0]);
    if(index==-1)
        return 1;
    int option2=0;
       option2=1+solve1(S.substr(1),V.substr(index+1),dp);
    int ans=min(option1,option2);
    dp[S.length()][V.length()]=ans;
    return ans;
}
int solve(string S,string V)
{
	// Write your code here.
    int **dp=new int*[S.length()+1];
    for(int i=0;i<=S.length();i++){
        dp[i]=new int[V.length()+1];
        for(int j=0;j<=V.length();j++)
               dp[i][j]=-1;
    }
    return solve1(S,V,dp);  
}
