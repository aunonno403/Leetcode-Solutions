from typing import List
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
       n=len(triangle)
       for i in range(n-2,-1,-1):
           for j in range(len(triangle[i])):
               x=triangle[i+1][j]
               y=triangle[i+1][j+1]
               triangle[i][j]+=min(x,y)
       return triangle[0][0]
               
