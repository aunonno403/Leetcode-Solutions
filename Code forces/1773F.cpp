#include <bits/stdc++.h>
using namespace std;

// Can we build exactly m non-draw matches with total scored A and conceded B?
static bool feasibleNonDraw(int m, int A, int B) {
    if (A < 0 || B < 0) return false;
    if (m == 0) return (A == 0 && B == 0);
    if (m == 1) return (A != B);
    // m >= 2: each non-draw needs at least 1 total goal
    return (A + B >= m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    int bestM = -1, bestT = -1;

    for (int m = n; m >= 0; --m) {
        int d = n - m;

        if (d == 0) {
            // no draws => t must be 0
            if (feasibleNonDraw(m, a, b)) {
                bestM = m;
                bestT = 0;
                break;
            }
        } else {
            // choose t goals to go into draws (equal on both sides)
            for (int t = 0; t <= min(a, b); ++t) {
                int A = a - t, B = b - t;
                if (feasibleNonDraw(m, A, B)) {
                    bestM = m;
                    bestT = t;
                    break;
                }
            }
            if (bestM != -1) break;
        }
    }

    int m = bestM;
    int d = n - m;
    int t = bestT;
    int A = a - t, B = b - t;

    cout << d << '\n';

    vector<pair<int, int>> ans;

    // Build m non-draw matches for totals (A, B)
    if (m == 0) {
        // none
    } else if (m == 1) {
        ans.push_back({A, B}); // guaranteed A != B
    } else {
        // m >= 2
        if (A == 0) {
            // all losses: 0:1 base
            for (int i = 0; i < m; ++i) ans.push_back({0, 1});
            ans[0].second += (B - m);
        } else if (B == 0) {
            // all wins: 1:0 base
            for (int i = 0; i < m; ++i) ans.push_back({1, 0});
            ans[0].first += (A - m);
        } else {
            // mix wins/losses: p wins(1:0), q losses(0:1), p+q=m
            int p = max(1, m - B);
            p = min(p, m - 1);
            p = min(p, A);
            if (p == 0) p = 1;
            if (p == m) p = m - 1;
            int q = m - p;

            for (int i = 0; i < p; ++i) ans.push_back({1, 0});
            for (int i = 0; i < q; ++i) ans.push_back({0, 1});

            int remA = A - p;
            int remB = B - q;

            ans[0].first += remA;    // keep a win
            ans[p].second += remB;   // keep a loss
        }
    }

    // Build d draws with total t on each side
    if (d > 0) {
        ans.push_back({t, t});
        for (int i = 1; i < d; ++i) ans.push_back({0, 0});
    }

    // Safety (should already be n)
    while ((int)ans.size() < n) ans.push_back({0, 0});

    for (auto &sc : ans) {
        cout << sc.first << ':' << sc.second << '\n';
    }

    return 0;
}