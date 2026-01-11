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
    unordered_map<int,int>map;
    int maxLevelSum(TreeNode* root) {
        map.clear();
        BFS(root,1);
        int max_lvl = 1;
        int max_sum = INT_MIN;
        for(auto& [lvl,sum]:map)
        {
            if(sum>max_sum || (sum == max_sum && lvl < max_lvl))
            {
                max_lvl=lvl;
                max_sum=sum;
            }
        }
        return max_lvl;
        
    }
    void BFS(TreeNode* node,int lvl)
    {
        if(node==NULL) return;
        map[lvl]+=node->val;
        BFS(node->left,lvl+1);
        BFS(node->right,lvl+1);
    }
};