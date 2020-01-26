#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int *strnth=new int[n];
    for(int i=0;i<n;i++)
        cin>>strnth[i];
    int *counts=new int[1024];
    int *xorcount=new int[1024];
    memset(xorcount,0,1024*sizeof(int));
    memset(counts,0,1024*sizeof(int));
    for(int i=0;i<n;i++)
        counts[strnth[i]]++;
     for(int i=0;i<k;i++){
         int count=0;
         for(int j=0;j<1024;j++){
             if(counts[j]!=0){
             int y=counts[j]/2;
              if( (count&1)==0 && (counts[j]&1)==1)
                    y++;
              int z=j^x;
             xorcount[z]+=y;
             xorcount[j]=counts[j]-y;
             count+=counts[j];
             }
         }
          memset(counts,0,1024*sizeof(int));
         swap(xorcount,counts);
     }
    for(int i=1023;i>=0;i--)
         if(counts[i]!=0){
              cout<<i<<" ";
             break;
         }
     for(int i=0;i<1024;i++)
         if(counts[i]!=0){
              cout<<i;
             break;
         }
    return 0;
}
