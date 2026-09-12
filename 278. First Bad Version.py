# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

def isBadVersion(y): pass

class Solution:
    def firstBadVersion(self, n: int) -> int:
        if isBadVersion(1):
            return 1

        lo,hi=1,n
        while(lo<hi):
            x=(lo+hi)//2
            if isBadVersion(x):
                hi=x
            else:
                lo=x+1

        return lo

       