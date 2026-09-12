from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k=0
        pt=len(nums)-1
        for i in range(len(nums)):
            if nums[i]==val:
                nums[i]=51
            else:
                k+=1
        nums.sort()
        return k