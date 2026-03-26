#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        string ans;
        string alphabets="abc";
        string vis;
        dfs(n,alphabets,ans,vis,k);
        return ans;
    }

    void dfs(int n,string alphabets,string &ans,string &vis,int &k)
    {
        if(!ans.empty()) return;
        if(vis.size()==n)
        {
            --k;
            if(k==0){
                ans=vis;
            } 
            return;
        }
        for(auto ch:alphabets)
        {
            if(!vis.empty()&&vis.back()==ch) continue;
            vis.push_back(ch);
            dfs(n,alphabets,ans,vis,k);
            vis.pop_back();
            if(!ans.empty()) return;
        }

    }
};