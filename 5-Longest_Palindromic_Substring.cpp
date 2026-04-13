#include <bits/stdc++.h>
using namespace std;

class manacher {
public:
    vector<int> p;
    string ms;

    manacher(string &s) {
        ms = "@";
        for (char c : s) ms += "#" + string(1, c);
        ms += "#$";
        runManacher();
    }

    void runManacher() {
        int n = (int)ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mir = l + r - i;
            if (i < r && mir >= 0 && mir < n) {
                p[i] = min(r - i, p[mir]);
            }

            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]]) {
                ++p[i];
            }

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }
};

// forward declaration
string getLongestPal(string &s);

class Solution {
public:
    string longestPalindrome(string s) {
        return getLongestPal(s);
    }
};

string getLongestPal(string &s) {
    if (s.empty()) return "";

    int n = (int)s.size(), maxLen = 1, start = 0;
    manacher M(s);

    for (int i = 0; i < n; ++i) {
        int oddLen = M.getLongest(i, 1);
        if (oddLen > maxLen) {
            maxLen = oddLen;
            start = i - (oddLen - 1) / 2;
        }

        int evenLen = M.getLongest(i, 0);
        if (evenLen > maxLen) {
            maxLen = evenLen;
            start = i - (evenLen - 1) / 2;
        }
    }

    return s.substr(start, maxLen);
}