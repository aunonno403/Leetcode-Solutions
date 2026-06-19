from typing import List
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        ans=0
        n=len(grid)
        rows: list[list[int]]=[]
        for i in range(n):
            rows.append([])
            for j in range(n):
                rows[i].append(grid[j][i])
            #if rows[i] in grid: ans+=1
        for i in grid:
            for j in rows:
                if i==j: ans+=1
        return ans