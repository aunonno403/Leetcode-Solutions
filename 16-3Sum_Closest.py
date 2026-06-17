from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        # Initialize ans with the sum of the first three numbers
        ans = nums[0] + nums[1] + nums[2]

        for i in range(n - 2):
            # Skip duplicate elements (optional optimization)
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = n - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]

                # Update ans if this total is closer to target
                if abs(target - total) < abs(target - ans):
                    ans = total

                if total < target:
                    left += 1
                elif total > target:
                    right -= 1
                else:
                    # Exact match found
                    return total

        return ans