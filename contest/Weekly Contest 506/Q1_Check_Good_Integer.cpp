#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkGoodInteger(int n) {
        string s=to_string(n);
        long long digsum=0,sqrtsum=0;
        for(char it:s)
        {
            int x=it - '0';
            digsum+=x;
            sqrtsum+=(x*x);            
        }
        return (sqrtsum-digsum>=50);

    }
};