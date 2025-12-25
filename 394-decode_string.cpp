#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        string ans;
        string content;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                content.clear();

                
                while (!ans.empty() && ans.back() != '[') {
                    content.insert(0, 1, ans.back());
                    ans.pop_back();
                }

                
                if (!ans.empty() && ans.back() == '[') {
                    ans.pop_back();
                }

                
                string numStr;
                while (!ans.empty() && isdigit(static_cast<unsigned char>(ans.back()))) {
                    numStr.insert(0, 1, ans.back());
                    ans.pop_back();
                }
                int n = numStr.empty() ? 1 : stoi(numStr);

                
                for (int k = 0; k < n; ++k) {
                    ans += content;
                }
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};