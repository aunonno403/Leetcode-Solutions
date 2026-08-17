class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle not in haystack: return -1
        n=len(haystack)
        m=len(needle)
        flg=False
        ans=0
        for i in range(n):
            for j in range(m):
                if haystack[i+j]!=needle[j]:
                    flg=False
                    break
                flg=True
            if flg==True: 
                ans=i
                break

        return ans

