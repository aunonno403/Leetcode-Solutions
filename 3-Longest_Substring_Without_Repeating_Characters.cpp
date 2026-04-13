#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> fq;
        int left = 0, ans = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            while (fq.find(s[right]) != fq.end()) {
                fq.erase(s[left]);
                ++left;
            }
            fq.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
int main()
{
    string s="aabcde";
   Solution x;
   int as= x.lengthOfLongestSubstring(s);
   cout<<as;

}