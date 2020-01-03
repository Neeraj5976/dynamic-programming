#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
     int sum1=0;
    int sum2=0;
    int *arr1=new int[n];
       arr1[0]=arr[0];
    for(int i=1;i<n;i++){
            sum1=0;
           for(int j=i-2;j>=0;j--)
                sum1=max(arr1[j],sum1);
            arr1[i]=arr[i]+sum1;
        }
     sort(arr1,arr1+n);  
    int ans=arr1[n-1];
    delete []arr1;
    return ans;
}
