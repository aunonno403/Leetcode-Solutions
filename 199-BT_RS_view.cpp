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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        BFS(root,0,ans);
        return ans;
    }
    void BFS(TreeNode* node,int lvl,vector<int> &ans)
    {
        if(node==NULL) return;
        if(node!=NULL&&ans.size()==lvl) ans.push_back(node->val);
        BFS(node->right,lvl+1,ans);
        BFS(node->left,lvl+1,ans);
    }
};