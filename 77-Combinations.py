from typing import List
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if n==1: return [[1]]
        ans:List[List[int]]=[]

        def bt(lis,curr):
            if len(lis)==k:
                ans.append(lis.copy())
                return
            
            for i in range(curr,n+1):
                lis.append(i)
                bt(lis,i+1)
                lis.pop()

        bt([],1)
        return ans

