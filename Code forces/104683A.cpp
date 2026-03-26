#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        long long k=n/m;
        long long s=m*k*(k+1)/2;
        cout<<s<<'\n';
    }
    return 0;
}