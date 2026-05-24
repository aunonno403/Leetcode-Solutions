from typing import List
class Solution:
    def findCoins(self, numWays: List[int]) -> List[int]:
        n= len(numWays)
        if n==1:
            if numWays[0]==1:
                return [1]
            else:
                return []
        dp : List[int] = [0]*(n+1)
        dp[0]=1
        ans =[]
        def update_dp(dp,c):
            for i in range(c,n+1):
                dp[i]+=dp[i-c]
        for i in range(n):
            if (numWays[i]-dp[i+1])==1:
                ans.append(i+1)
                update_dp(dp,i+1)
            elif (numWays[i]-dp[i+1]) !=0:
                return []
        return ans
       