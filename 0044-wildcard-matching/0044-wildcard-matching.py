class Solution:
    def sol(self,s: str, p: str,i: int,j: int,dp: List[List[int]] ):
        if i<0 and j<0 :
            return True
        if j<0 :
            return False
        if i<0:
            while j>=0:
                if p[j]!='*':
                    return False
                j-=1
            return True
        
        if dp[i][j]!=-1:
            return dp[i][j]
        if s[i]==p[j] or p[j]=='?':
            dp[i][j] = self.sol(s,p,i-1,j-1,dp)
            return dp[i][j]
        elif p[j]=='*':
            dp[i][j] = self.sol(s,p,i-1,j,dp) or self.sol(s,p,i,j-1,dp)
            return dp[i][j]
        return False
        
    def isMatch(self, s: str, p: str) -> bool:
        dp=[[-1]* (len(p)+1) for _ in range(len(s)+1)]
        return self.sol(s,p,len(s)-1,len(p)-1,dp)
        