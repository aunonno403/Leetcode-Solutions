from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n = len(nums)
        prfx = [0]
        for x in nums:
            prfx.append(prfx[-1] + x)

        min_idx = 0
        mx = nums[0]

        for it in range(1, n + 1):
            mx = max(mx, prfx[it] - prfx[min_idx])
            if prfx[it] < prfx[min_idx]:
                min_idx = it

        return mx