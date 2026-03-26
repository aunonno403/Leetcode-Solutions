#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool mycomp(string &a,string &b)
{
    return a.size()<b.size();
}

int main()
{
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s.begin(),s.end(),mycomp);
    ll ans=n;
    map<pair<ll,ll>,ll> frq;

    for(auto it:s)
    {
        ll n=it.size();
        for(ll i=1;i<=n;i++)
        {
            if((n+i)%2!=0) continue;
            ll mid=(n+i)/2;
            ll req=0;
            for(ll j=0;j<mid;j++) req+=(it[j]-'0');
            for(ll j=mid;j<n;j++) req-=(it[j]-'0');

            if(req>=0) ans+= frq[{i,req}];
        }

        reverse(it.begin(),it.end());
        for(ll i=1;i<=n;i++)
        {
            if((n+i)%2!=0) continue;
            ll mid=(n+i)/2;
            ll req=0;
            for(ll j=0;j<mid;j++) req+=(it[j]-'0');
            for(ll j=mid;j<n;j++) req-=(it[j]-'0');

            if(req>=0) ans+= frq[{i,req}];
        }
        ll sum=0;
        for(auto x:it) sum+=(x-'0');
        frq[{n,sum}]++;

    }

    cout<<ans<<'\n';
    return 0;

}