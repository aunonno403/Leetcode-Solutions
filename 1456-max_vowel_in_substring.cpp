#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
      unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
      int max_cnt=0,cnt=0;
      for(int i=0;i<k;i++)
      {
        if(vowels.count(s[i])) cnt++;
      }
      max_cnt=cnt;
      if(s.size()==k||max_cnt==k) return max_cnt;
      int i=0,j=k;
      while(j<s.size())
      {
        if(vowels.count(s[j]))cnt++;
        if(vowels.count(s[i]))cnt--;
        if(cnt>max_cnt)
        {
            max_cnt=cnt;
            if(max_cnt==k) return max_cnt;
        }
        i++;
        j++;
      }
      return max_cnt;

        
    }
};