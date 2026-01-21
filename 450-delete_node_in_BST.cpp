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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key>root->val) root->right=deleteNode(root->right,key);
        else if(key<root->val) root->left=deleteNode(root->left,key);
        else{
            if (!root->left && !root->right) return nullptr;
            if(!root->left||!root->right) return root->left==NULL? root->right:root->left;
            TreeNode* minright=root->right;
            while(minright->left)minright=minright->left;
            root->val=minright->val;
            root->right=deleteNode(root->right,root->val);
        }
        return root;
        
    }
};