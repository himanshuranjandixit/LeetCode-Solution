class Solution:
    def sol(self, word1: str, word2: str, i: int, j: int,dp: List[List[int]]) -> int:
        if i==-1:
            return j+1
        if j==-1:
            return i+1
        if dp[i][j]!=-1:
            return dp[i][j]
        if word1[i]==word2[j]:
            dp[i][j] = self.sol(word1,word2,i-1,j-1,dp)
            return dp[i][j]
        else:
            dp[i][j] = 1+ min(self.sol(word1,word2,i-1,j,dp),min(self.sol(word1,word2,i,j-1,dp),self.sol(word1,word2,i-1,j-1,dp)))
            return dp[i][j]
    def minDistance(self, word1: str, word2: str) -> int:
        dp=[[-1]*(len(word2)+1) for _ in range(len(word1)+1)]
        return self.sol(word1,word2,len(word1)-1,len(word2)-1,dp)
        