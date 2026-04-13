// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     vector<pair<int,multiset<int>>> frq(k+1);
//     vector<int>jobs;
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         jobs.push_back(x);
//         frq[x].first++;
//     }
//     int cnt=0; //count number of jobs not yet taken.
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         frq[jobs[i]].second.insert(x);
//     }
//     for (int job = 1; job <= k; job++) {
//     if (frq[job].first == 0) cnt++;
//     }    
    
//     if(cnt==0){
//         cout<<0;
//         return 0;
//     }
//     int ans=0;
    
//     while(cnt)
//     {
//         int mn=INT_MAX;
//         int curr;
//         for(int i=1;i<=k;i++)
//         {
//             if(frq[i].first>1&&*frq[i].second.begin()<mn)
//             {
//                 mn=*frq[i].second.begin();
//                 curr=i;
//             }

//         }
//         ans+=mn;
//         frq[curr].first--;
//         frq[curr].second.erase(frq[curr].second.begin());
//         cnt--;

//     }
//     cout<<ans;
//     return 0;

// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    vector<vector<int>> costs(k + 1);
    vector<int> cnt(k + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        costs[a[i]].push_back(b[i]);
    }

    int missing = 0;
    for (int job = 1; job <= k; job++) {
        if (cnt[job] == 0) missing++;
    }

    if (missing == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> extras;
    extras.reserve(n);


    for (int job = 1; job <= k; job++) {
        if (costs[job].empty()) continue;
        sort(costs[job].begin(), costs[job].end()); // ascending
        for (int i = 0; i + 1 < (int)costs[job].size(); i++) {
            extras.push_back(costs[job][i]);
        }
    }

    sort(extras.begin(), extras.end());

    long long ans = 0;
    for (int i = 0; i < missing; i++) {
        ans += extras[i];
    }

    cout << ans << '\n';
    return 0;
}