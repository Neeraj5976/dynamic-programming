#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
 map<string,bool> m1;
int sub_sequence(string s,string s1){
    if(s.empty()){
        if(!m1[s1]){
            m1[s1]=true;
            return 1;
      }
        else
            return 0;
    } 
      long ans1=(long)sub_sequence(s.substr(1),s1+s[0]);
      long ans2=(long)sub_sequence(s.substr(1),s1);
      int ans3=(int)(ans1%m);
      int ans4=(int)(ans2%m);
      int ans=(ans3+ans4)%m;
    return ans;
}
int main()
{
    int t;
    string s,s1;
    cin>>t;
    while(t--){
        cin>>s;
          s1="";
        cout<<sub_sequence(s,s1)<<endl;
        m1.clear();
    }
    return 0;
}
