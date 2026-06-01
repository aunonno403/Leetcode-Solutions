# from typing import List
# import bisect

# class Solution:
#     def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
#         n = len(spells)
#         m = len(potions)
#         potions.sort()                 
#         ans: List[int] = []
#         for x in spells:
#             need = (success + x - 1) // x
#             idx = bisect.bisect_left(potions, need)
#             ans.append(m - idx)
#         return ans
from typing import List

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        m = len(potions)
        ans: List[int] = []

        for s in spells:
            need = (success + s - 1) // s  # ceil(success / s)
            # lower_bound: first index with potions[idx] >= need
            l, r = 0, m
            while l < r:
                mid = (l + r) // 2
                if potions[mid] < need:
                    l = mid + 1
                else:
                    r = mid
            ans.append(m - l)

        return ans