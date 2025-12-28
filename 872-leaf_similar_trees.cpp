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
    private:
    vector<int>l1;
    vector<int>l2;
    public:
    void in_order(TreeNode *root, vector<int>& l) {
        if (!root) return;  
        
        if (!root->left && !root->right) {  
            l.push_back(root->val);
            return;  
    }    
    in_order(root->left, l);
    in_order(root->right, l);
    }  
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        in_order(root1,l1);
        in_order(root2,l2);
        bool ans=(l1==l2)? true:false;
        l1.clear();
        l2.clear();
        return ans;            
        }
};