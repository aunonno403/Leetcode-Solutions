#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    vector<pair<char,int>> frq;
    for (char c : s) {
        if (frq.empty() || frq.back().first != c) frq.push_back({c, 1});
        else frq.back().second++;
    }
    int m = (int)frq.size();
    if (m % 2 == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int mid = m / 2;
    if (frq[mid].second < 2) {
        cout << 0 << '\n';
        return 0;
    }

    for (int d = 1; mid - d >= 0 && mid + d < m; d++) {
        auto L = frq[mid - d];
        auto R = frq[mid + d];
        if (L.first != R.first || L.second + R.second < 3) {
            cout << 0 << '\n';
            return 0;
        }
    }

    cout << (frq[mid].second + 1) << '\n';
    return 0;
    
}