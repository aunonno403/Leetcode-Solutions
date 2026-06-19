from typing import List
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans: List[List[int]] =[]

        def bt(list:List[int],sum,st):
            if len(list)==k and sum==n:
                ans.append(list.copy())
                return
            for i in range(st+1,10):
                if(sum+i>n) or len(list)>=k: break
                list.append(i)
                bt(list,sum+i,i)
                list.pop()
            

        bt([],0,0)
        return ans
        