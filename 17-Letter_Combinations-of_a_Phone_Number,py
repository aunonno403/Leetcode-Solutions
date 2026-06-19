from typing import List
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ref = ['abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
        ans=[]

        def bt(index,curr):
            if index==len(digits):
                ans.append(curr)
                return
            for x in ref[int(digits[index])-2]:
                bt(index+1,curr+x)
        
        bt(0,'')
        return ans
