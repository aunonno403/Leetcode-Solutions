#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> h;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            h.push_back(x);
        }
        sort(h.begin(), h.end());
        cout<<(h.back()-h.front())+1<<endl;
    }
    return 0;
}