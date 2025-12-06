#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int l=flowerbed.size();
        int i=0;
        if(l==1)
        {
            if(n==1&&flowerbed[i]==0) return true;
            else return false;
        }
        if(flowerbed[i]==0&&flowerbed[i+1]==0)
        {
            flowerbed[i]=1;
            n--;
            i++;
        }
        else i++;
        while(n&&i<l-1)
        {
            if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                n--;
            }
            i++;
        }
        if(n==0) return true;
        if(flowerbed[i]==0&&flowerbed[i-1]==0)
        {
            flowerbed[i]==0;
            n--;
        }
        if(n==0) return true;

        return false;

        
    }
};