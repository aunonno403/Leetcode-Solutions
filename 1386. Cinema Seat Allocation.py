from collections import defaultdict
from typing import List

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        rows = defaultdict(set)
        for r, c in reservedSeats:
            rows[r].add(c)
        # untouched rows fit 2 families each
        ans = (n - len(rows)) * 2
        for taken in rows.values():
            left  = not (taken & {2, 3, 4, 5})
            mid   = not (taken & {4, 5, 6, 7})
            right = not (taken & {6, 7, 8, 9})
            if left and right: ans += 2
            elif left or mid or right: ans += 1
        return ans
