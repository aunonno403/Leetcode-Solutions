#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *curr=head;
        vector<int> col;
        while(curr)
        {
            col.push_back(curr->val);
            curr=curr->next;
        }
        int n=col.size();
        int mx=0;
        int i=0,j=n-1;
        while(i<j)
        {
            mx=max(mx,(col[i]+col[j])); 
            i++;
            j--;
        }
        return mx;
        
    }
};