#include<bits/stdc++.h>
using namespace std;
long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long *arr=new long[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=4;i<=n;i++)
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    long ans=arr[n];
    delete []arr;
    return ans;
    
}
