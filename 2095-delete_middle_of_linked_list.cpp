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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        int size=0;
        ListNode *curr=head;
        while(curr)
        {
            size++;
            curr=curr->next;
        }
        int n=size/2;
        curr=head;
        for(int i=0;i<n-1;i++)
        {
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
        
    }
};