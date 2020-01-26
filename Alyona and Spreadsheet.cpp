#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,k;
    cin>>n>>m;
    int **table=new int*[n];
     int **grid=new int*[n];
    for(int i=0;i<n;i++){
        table[i]=new int[m];
        grid[i]=new int[m];
        for(int j=0;j<m;j++)
            cin>>table[i][j];
     }
    // memset(grid,0,n*m*sizeof(int));
     for(int i=0;i<m;i++)
          grid[0][i]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
            if(table[i][j]>=table[i-1][j])
                grid[i][j]=grid[i-1][j]+1;
           else
               grid[i][j]=1;
    cin>>k;
     for(int i=0;i<k;i++){
         int l,r;
         cin>>l>>r;
         int row=r-1;
           int col=0;
         for(;col<m;col++)
               if(grid[row][col]>=r-l+1){
                    cout<<"Yes";
                   break;
               }
             if(col==m)
                 cout<<"No";
          cout<<endl;
         }
    
    return 0;
}






