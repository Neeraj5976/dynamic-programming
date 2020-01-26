#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,k;
    cin>>n>>k;
    ll *arr=new ll[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll *sum=new ll[n];
    sort(arr,arr+n);
    sum[0]=arr[0];
    for(int i=1;i<n;i++)
        sum[i]=arr[i]+sum[i-1];
    ll total=arr[1]-arr[0];
    for(int i=2;i<k;i++)
        total+=i*arr[i]-sum[i-1];
    ll m_total=total;
    for(int i=k;i<n;i++){
        total+=(k-1)*arr[i]+(k-1)*arr[i-k]-2*sum[i-1]+2*sum[i-k];
        m_total=min(m_total,total);
    }
    cout<<m_total;
    delete []arr;
    delete []sum;
    return 0;
}
