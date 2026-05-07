#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        else if (rowIndex==1)
        {
            return {1,1};
        }
        vector<vector<int>> ans={{1},{1,1}};
        vector<int> curr= {1,1};
        for(int i=1;i<rowIndex;i++)
        {
            vector<int> nw(curr.size()+1);
            nw[0]=1;
            nw[nw.size()-1]=1;
            for(int j=1;j<nw.size()-1;j++)
            {
                nw[j]=curr[j]+curr[j-1];
            }
            ans.push_back(nw);
            curr=nw;
        }
        return ans.back();
       // return ans;   
    }
};