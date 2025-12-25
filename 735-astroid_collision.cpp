#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        ans.push_back(asteroids[0]);
        for(int i=1;i<asteroids.size();i++)
        {
            if(ans.empty()) {
            ans.push_back(asteroids[i]);
            continue;
            }
            int s0=(ans.back()>0),s1=(asteroids[i]>0);
            if(s0&&s1==0){
                if(abs(ans.back())==abs(asteroids[i])) ans.pop_back();
                else{
                    bool flg=true;
                    for(int j=ans.size()-1;j>=0;j--)
                    {
                        int s3=(ans[j]>0);
                        if(s3==0)
                        {
                            break;
                        }
                        if(abs(asteroids[i])>abs(ans[j]))
                        {
                            ans.pop_back();
                        }
                        else if (abs(asteroids[i])==abs(ans[j]))
                        {
                            ans.pop_back();
                            flg=false;
                            break;
                        }                        
                        else {flg=false;
                        break;}
                    }
                    if(flg) ans.push_back(asteroids[i]);
                }

            }
            else ans.push_back(asteroids[i]);
        }
        return ans;
        
    }
};