//DP approach (Just for practice)
// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = (int)prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 int cur = 0;
//                 if (i < j) cur = prices[j - 1] - prices[i - 1]; // valid buy/sell order only

//                 dp[i][j] = max(cur,
//                            max(dp[i - 1][j - 1],
//                            max(dp[i - 1][j], dp[i][j - 1])));
//             }
//         }
//         return dp[n][n];
//     }
// };
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int best = 0;

        for (int p : prices) {
            minPrice = min(minPrice, p);
            best = max(best, p - minPrice);
        }

        return best;
    }
};