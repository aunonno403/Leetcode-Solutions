#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        stack<int>st;
        vector<int>vis(n,0);
        st.push(0);
        while (!st.empty())
        {
            int node=st.top();
            st.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(int i:rooms[node]) if(!vis[i]) st.push(i);
        }

        for(int i:vis) if(!i) return false;

        return true;
        
        
    }
};