#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> fst,snd,thrd;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') fst.push_back(i);
            else if(s[i]=='2') snd.push_back(i);
            else thrd.push_back(i);
        }
        if(fst.empty()||snd.empty()||thrd.empty())
        {
            cout<<0<<endl;
            continue;
        }
        int i=0,j=0,k=0;
        int ans=INT_MAX;
        while(i<fst.size()&&j<snd.size()&&k<thrd.size())
        {
            int mx = max({fst[i], snd[j], thrd[k]});
            int mn = min({fst[i], snd[j], thrd[k]});
            int curr = mx - mn + 1;
            if(curr<ans) ans=curr;

            if(ans==3) break;

            int x=mn;

            if(fst[i]==x) i++;
            else if(snd[j]==x) j++;
            else k++;
        }
        cout<<ans<<endl;
    }
    return 0;
}