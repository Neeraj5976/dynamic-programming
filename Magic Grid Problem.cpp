#include <bits/stdc++.h>
using namespace std;
int magic_grid(int **grid,int n,int m){
        int **grid1=new int*[n];
    for(int i=0;i<m;i++)
          grid1[i]=new int[m];
      grid1[n-1][m-1]=0;
    for(int i=n-2;i>=0;i--){
         grid1[i][m-1]=grid1[i+1][m-1]-grid[i+1][m-1];
          if(grid1[i][m-1]<=0)
              grid1[i][m-1]=1;
        }
    for(int i=m-2;i>=0;i--){
         grid1[n-1][i]=grid1[n-1][i+1]-grid[n-1][i+1];
          if(grid1[n-1][i]<=0)
              grid1[n-1][i]=1;
        }
     for(int i=n-2;i>=0;i--)
           for(int j=m-2;j>=0;j--){
               int x=grid1[i+1][j]-grid[i+1][j];
               int y=grid1[i][j+1]-grid[i][j+1];
              grid1[i][j]=min(x,y);
             if(grid1[i][j]<=0)
                   grid1[i][j]=1;
        }
    return grid1[0][0];               
}
int main() {
	int n,m,t;
    cin>>t;
    while(t--){
	cin>>n>>m;
	int **grid=new int*[n];
	for(int i=0;i<n;i++){
	    grid[i]=new int[m];
	    for(int j=0;j<m;j++)
	      cin>>grid[i][j];
    }
	cout<<magic_grid(grid,n,m)<<endl;
  }
    return 0;
}


