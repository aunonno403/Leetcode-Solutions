#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        vector<int> fq(n + 1);
        fq[0] = 0;
        fq[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            fq[i] = fq[i-1] + fq[i-2];
        }
        
        return fq[n];
    }
};