#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int **grid=new int*[n];
  //  memset(arr,0,m*sizeof(int));
    for(int i=0;i<n;i++){
        grid[i]=new int[m];
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    
    int current_sum=0;
    int max_sum=INT_MIN;
    int *arr=new int[n];
    for(int left=0;left<m;left++){
        memset(arr,0,(n)*sizeof(int));
        for(int right=left+1;right<=m;right++){
                 for(int row=0;row<n;row++){
                    arr[row]+=grid[row][right-1];
                      current_sum+=arr[row];
                      max_sum=max(current_sum,max_sum);
                     if(current_sum<0)
                         current_sum=0;
                      }
                     current_sum=0;    
                  }
    }
    cout<<max_sum;
    for(int i=0;i<n;i++)
         delete []grid[i];
    delete []grid;
   // delete []arr;
   return 0;
}
