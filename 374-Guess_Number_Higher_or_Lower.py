from typing import List
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        st, end = 1, n

        while st <= end:
            mid = st + (end - st) // 2
            res = guess(mid)

            if res == 0:
                return mid
            elif res == 1:
                st = mid + 1
            else:
                end = mid - 1

        return -1
        
            