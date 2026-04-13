#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='u'&& i==0)
            {
                s[i]='s';
                ans++;
                continue;
            }
            
            if(s[i]=='u'&& i==s.size()-1)
            {
                s[i]='s';
                ans++;
                continue;
            }
            if(s[i]=='u'&& s[i-1]!='s')
            {
                s[i]='s';
                ans++;
            }
            
        }
        cout<<ans<<endl;
    }
}