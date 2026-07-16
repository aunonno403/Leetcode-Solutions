from typing import List
from math import gcd

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        if len(nums)==1:
            return 0
        
        ls=[]
        mx=nums[0]

        for i in nums:
            if i>mx:
                mx=i
            ls.append(gcd(i,mx))
        
        ls.sort()
        sum=0
        left=0
        right=len(ls)-1
        while(right>left):
            sum+=gcd(ls[left],ls[right])
            left+=1
            right-=1
        return sum
