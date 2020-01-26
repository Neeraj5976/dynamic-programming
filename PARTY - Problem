#include <bits/stdc++.h>
using namespace std;
   void party_problem(int* wt,int* val,int n,int W){
	int** dp = new int*[n+1];
	int** dp1 = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[W+1];
	    dp1[i] = new int[W+1];
	}

	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
		dp1[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
		dp1[i][0] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int w=0;w<=W;w++){
			dp[i][w] = dp[i-1][w];
			dp1[i][w] = dp1[i-1][w];
			if(wt[i-1] <= w){
                if(dp[i][w]<(val[i-1] + dp[i-1][w-wt[i-1]]) )
					 	 dp1[i][w] = wt[i-1] + dp1[i-1][w-wt[i-1]];
				dp[i][w] = max(dp[i][w],val[i-1] + dp[i-1][w-wt[i-1]]);
			}
		
		}
	}
     //   for(int i=0;i<=n;i++){
     //     for(int j=0;j<=W;j++)
     //     cout<<dp1[i][j]<<" ";
     //     cout<<endl;
     // }
       cout<<dp1[n][W]<<" "<<dp[n][W];
       for(int i=0;i<=n;i++){
             delete []dp[i];
            delete []dp1[i];
       }
       cout<<endl;
         delete []dp;
	     delete []dp1; 
	
}
int main()
{
    
    while(1){
        int budjet,n_parties;
         cin>>budjet>>n_parties;
        if(budjet==0 && n_parties==0)
             break;
        int *entrance=new int[n_parties];
        int *fun_values=new int[n_parties];
        for(int i=0;i<n_parties;i++)
             cin>>entrance[i]>>fun_values[i];
        party_problem(entrance,fun_values,n_parties,budjet);
        delete []entrance;
        delete []fun_values;
    }
    return 0;
}
