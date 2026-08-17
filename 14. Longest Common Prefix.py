from typing import List
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n=len(strs)
        if n==1: return strs[0]
        x=min(len(strs[0]),len(strs[1]))
        ans=""
        for i in range(x):
            if(strs[0][i]==strs[1][i]): ans+=(strs[0][i])
            else: break
        if n==2: return ans

        def helper(st1,st2):
            x=min(len(st1),len(st2))
            res=""
            for i in range(x):
                if(st1[i]==st2[i]): res+=st1[i]
                else: break
            return res

        for i in range(2,n):
            ans=helper(ans,strs[i])

        return ans

