#include <bits/stdc++.h>
using namespace std;
int main()
{
  int  n,m,q;
    cin>>n;
    int *start=new int[n+1];
    int *end=new int[n+1];
    int *arr=new int[n+1];
    cin>>m;
    memset(start,0,(n+1)*sizeof(int));
    memset(end,0,(n+1)*sizeof(int));
    memset(arr,0,(n+1)*sizeof(int));
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        start[l]++;
        end[r]++;
    }
    arr[1]=start[1];
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+start[i]-end[i-1];
        
    }
    int *c_counts=new int[n+1];
     memset(c_counts,0,(n+1)*sizeof(int));
    cout<<endl;
    for(int i=1;i<=n;i++)
         c_counts[arr[i]]++;
     for(int i=n-1;i>=1;i--)
          c_counts[i]+= c_counts[i+1];
     cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        cout<<c_counts[x]<<endl;
    }
    delete []start;
    delete []end;
    delete []arr;
    delete []c_counts;
    return 0;
}
