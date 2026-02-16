#include<bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int>before;   
    int curr;
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        if(!pq.empty())
        {
            int x=pq.top();
            before.insert(x);
            pq.pop();
            return x;
        }
        before.insert(curr);
        return curr++;
        
    }
    
    void addBack(int num) {
        if(before.find(num)!=before.end()&&num<curr)
        {
            pq.push(num);
            before.erase(num);
        }        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */