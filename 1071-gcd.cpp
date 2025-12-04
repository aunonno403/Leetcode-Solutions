#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s="";
        if(str2.length()>str1.length()) swap(str1,str2);
        int x=str1.length(),y=str2.length();
        while(y)
        {
            if(x%y==0 && str2.length()%y==0)
            {
                string mat=str2.substr(0,y);
                bool flag=true;
                for(int i=0;i<x;i+=y)
                {
                    if(str1.substr(i,y)!=mat) flag=false;
                }
                for(int i=0;i<str2.length();i+=y)
                {
                    if(str2.substr(i,y)!=mat) flag=false;
                }
                if(flag==false) {y--;
                    continue;}
                s=mat;
                return s;

            }
            else y--;
        }
        return s;
        
    }
};