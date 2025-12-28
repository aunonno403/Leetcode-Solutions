// #include<bits/stdc++.h>
// using namespace std;
// class RecentCounter {
//     private:
//     vector<int> collection;
//     public:
//     RecentCounter() {
//         collection.clear();
//     }
    
//     int ping(int t) {
//         collection.push_back(t);
//         int count=0;
//         for(auto& it:collection)
//         {
//             if((it<=t&&it>=(t-3000))||(((it-3000)<=t&&(it-3000)>=(t-3000)))) count++;
//         }
//         return count;
//     }
// };
#include<bits/stdc++.h>
using namespace std;

class RecentCounter {
private:
    queue<int> pings;
    
public:
    RecentCounter() {
        // queue is empty by default
    }
    
    int ping(int t) {
        pings.push(t);
        
        // Remove pings older than t - 3000
        while (!pings.empty() && pings.front() < t - 3000) {
            pings.pop();
        }
        
        return pings.size();
    }
};