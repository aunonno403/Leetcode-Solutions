from typing import List
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n=len(nums)-1
        nums.sort()
        ans=[]

        for i in range(n-2):
            if i>0 and nums[i]==nums[i-1]: continue

            for j in range(i+1,n-1):
                if j>i+1 and nums[j]==nums[j-1]:
                    continue
                left=j+1
                right=n
                while right>left:
                    sum=nums[i]+nums[j]+nums[left]+nums[right]
                    if sum>target:
                        right-=1
                    elif sum<target:
                        left+=1
                    else:
                        ans.append([nums[i],nums[j],nums[left],nums[right]])
                        left += 1
                        right -= 1

                        while left < right and nums[left] == nums[left - 1]:
                            left += 1

                        while left < right and nums[right] == nums[right + 1]:
                            right -= 1

        return ans