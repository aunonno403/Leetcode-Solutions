from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n=len(groups)
        ans_1 : List[str] =[]
        curr_1=1
        ans_0 : List[str] =[]
        curr_0=0
        for it in range(n):
            if groups[it]==curr_0:
                ans_0.append(words[it])
                if curr_0 ==0: curr_0=1
                else:curr_0=0
            if groups[it]==curr_1:
                ans_1.append(words[it])
                if curr_1==1: curr_1=0
                else: curr_1=1
        if(len(ans_0)>len(ans_1)) : return ans_0


        return ans_1