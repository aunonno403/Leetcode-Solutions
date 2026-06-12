#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n,k,flg=1;
       cin>>n>>k;
       string s;
       cin>>s;
       for(int i=0;i<n;i++)
       {
        if(s[i]=='1')
        {
           flg=0;
           for(int j=i+k;j<n;j+=k)
           {
            if(s[j]=='1')
            {
                flg=1;
                s[i]='0';
                s[j]='0';
                break;
            }
           }
           if(flg==0) break;
        }
       
       }
       if(flg==0) cout<<"NO";
       else cout<<"YES";
       cout<<endl;
    }
    return 0;
}