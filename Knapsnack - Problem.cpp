#include<bits/stdc++.h>
using namespace std;


int knapsnack(int* val,int* wt,int W,int n){
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[W+1];
	}

	for(int i=0;i<=W;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int w=0;w<=W;w++){

			dp[i][w] = dp[i-1][w];
			if(wt[i-1] <= w){
				dp[i][w] = max(dp[i][w],val[i-1] + dp[i-1][w-wt[i-1]]);
			}
		}
	}
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
              cout<<dp[i][j]<<" ";
        cout<<endl;
    }
	int ans = dp[n][W];
	//delete dp array 
	return ans;
}
int main(){
	
	int val[] = {2,3,5,7};
	int wt[] = {1,1,1,1};

	int W = 4;
	int n = 4;

	cout << knapsnack(val,wt,W,n)<<endl;
}
