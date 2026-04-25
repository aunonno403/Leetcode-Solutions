#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> l, r;
        
        int left = candidates - 1;        // rightmost index of left window
        int right = n - candidates;       // leftmost index of right window

        // TODO: seed the left heap with first `candidates` elements
        for(int i=0;i<=left;i++) l.push({costs[i],i});
        for(int i=n-1;i>=right && i>left;i--) r.push({costs[i],i});
        // TODO: seed the right heap with last `candidates` elements
        // (hint: be careful if left >= right, windows overlap)

        long long ans = 0;
        while(k--) {
        pair<int,int> l_top = l.empty() ? make_pair(INT_MAX, -1) : l.top(); 
        pair<int,int> r_top = r.empty() ? make_pair(INT_MAX, n)  : r.top(); // TODO: peek right heap (or {INT_MAX, n} if empty)

            if(l_top <= r_top) {  // pair comparison handles tiebreak automatically
                // TODO: pop from l, add cost to ans
                ans+=l_top.first;
                l.pop();
                // TODO: advance left pointer and push new element if left < right
                left++;
                if(left < right) l.push({costs[left],left});
            } else {
                ans+=r_top.first;
                r.pop();
                right--;
                if(left < right) r.push({costs[right],right}); // ✅
                // TODO: pop from r, add cost to ans
                // TODO: advance right pointer and push new element if left < right
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     long long totalCost(vector<int>& costs, int k, int candidates) {
//         vector<int> arr = costs;
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> r,l;
//         long long ans=0;
//         while(k--)
//         {
//             int n=candidates;
//             for(int i=0;i++;i<n)
//             {
//                 l.push({arr[i],i});
//             }
//             for(int i=arr.size()-1;i--;i>=(arr.size()-n))
//             {
//                 r.push({arr[i],i});
//             }
//             pair<int,int> x,y;
//             x=l.top();
//             y=r.top();
//             if(x.first==y.first)
//             {
//                 ans+=(x.second<y.second? x.first:y.first);
//                 if(x.second<y.second){
//                     arr.erase(arr.begin()+x.second);
//                     l.pop();
//                 }
//                 else{
//                     arr.erase(arr.begin()+y.second);
//                     r.pop();
//                 }
//             }
//             else if(x.first<y.first)
//             {
//                 ans+=x.first;
//                 arr.erase(arr.begin()+x.second);
//                 l.pop();
//             }
//             else{
//                 ans+=y.first;
//                 arr.erase(arr.begin()+y.second);
//                 r.pop();
//             }
//         }
//         return ans;
//     }
// };