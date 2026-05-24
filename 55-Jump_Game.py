from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        if n==1: return True
        # prev=0 
        curr = 0
        for i in range(n):
            if i > curr:
                return False
            curr = max(curr, i + nums[i])
            if curr >= n - 1:
                return True

        return curr >= n - 1