#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>rad,dir;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R') rad.push(i);
            else dir.push(i);
        }
        while(!rad.empty()&&!dir.empty())
        {
            int r=rad.front();
            int d=dir.front();
            rad.pop();
            dir.pop();
            if(r<d) rad.push(r+senate.size());
            else dir.push(d+senate.size());
        }
        return (rad.empty())? "Dire":"Radiant";
        
    }
};