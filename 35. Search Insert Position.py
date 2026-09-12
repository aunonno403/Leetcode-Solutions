from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        ans=len(nums)
        for i in range(len(nums)):
            if nums[i]>=target:
                ans=i
                break

        return ans
