#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count = 0;

    int minReorder(int n, vector<vector<int>>& connections) {
        count = 0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        // build graph; store original direction as positive, reverse as negative (with +1 offset to avoid -0)
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1] + 1);      // original direction
            adj[e[1]].push_back(-(e[0] + 1));   // reverse direction
        }

        dfs(0, adj, vis);
        return count;
    }

private:
    void dfs(int source, vector<vector<int>>& g, vector<bool>& vis) {
        stack<int> st;
        st.push(source);
        while (!st.empty()) {
            int v = st.top(); st.pop();
            if (vis[v]) continue;
            vis[v] = true;

            for (int x : g[v]) {
                int nei = abs(x) - 1;       // back to 0-index
                if (vis[nei]) continue;     // only process unvisited neighbors
                if (x > 0) count++;         // needs reorder
                st.push(nei);
            }
        }
    }
};