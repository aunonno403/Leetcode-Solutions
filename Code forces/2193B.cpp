#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int n,n1;
        cin>>n;
        n1=n;
        int perm[n];
        for(int i=0;i<n;i++)
        {
            cin>>perm[i];
        }
        int lb=0;
        while(perm[lb]==n&&n>0)
        {
            lb++;
            n--;
        }
        if(n==0){
            for( auto i:perm)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            
        }
        else
        {
            int j=n1-1;
            int mx=0;
            while(j>=lb)
            {
                if(perm[j]==n)
                {
                    mx=j;
                    break;
                }
                j--;
            }
            int cnt=(mx-lb+1)/2;
            while(cnt--)
            {
                swap(perm[lb],perm[mx]);
                lb++;
                mx--;
            }
            for( auto i:perm)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}