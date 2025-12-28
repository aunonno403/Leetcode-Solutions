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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *first_even=head->next;
        ListNode *curr_odd=head;
        ListNode *curr_even=head->next;
        while(curr_even && curr_even->next) {
            curr_odd->next = curr_even->next;      
            curr_odd = curr_odd->next;             
            curr_even->next = curr_odd->next;      
            curr_even = curr_even->next;           
        }
        curr_odd->next = first_even;
        return head;
    }
};