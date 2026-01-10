#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans=0;
        dfs(root,1,0,ans);
        dfs(root,0,0,ans);
        return ans;
    }
    void dfs(TreeNode* node,bool left,int length,int &ans)
    {
        if(!node) return;
        ans=max(ans,length);
        if(left)
        {
            dfs(node->left,0,length+1,ans);
            dfs(node->right,1,1,ans);
        }
        else{
            dfs(node->right,1,length+1,ans);
            dfs(node->left,0,1,ans);
        }

    }

};