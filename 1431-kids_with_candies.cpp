#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxval=*max_element(candies.begin(),candies.end());
        for (auto it:candies)
        {
            res.push_back((it+extraCandies>=maxval) ? true:false);
        }
        return res;
    }
};