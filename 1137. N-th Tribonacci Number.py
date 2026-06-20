from typing import List
class Solution:
    def tribonacci(self, n: int) -> int:
        ref:list[int] =[0]*(n+1)
        if n==2 or n==1: return 1
        elif n==0: return 0
        ref[1]=1
        ref[2]=1
        for i in range(3,n+1):
            ref[i]=ref[i-1]+ref[i-2]+ref[i-3]
        return ref[n]