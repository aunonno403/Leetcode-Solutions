from typing import List
from itertools import permutations

class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        ans: set[int] = set()
        for x in permutations(digits,3):
            a=x[0]*100 +x[1]*10+x[2]
            if a>=100 and a%2==0:
                ans.add(a)

        return len(ans)
               
        

        