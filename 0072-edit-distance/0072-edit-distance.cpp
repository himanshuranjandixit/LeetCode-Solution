class Solution {
public:
    int sol(string word1, string word2, int i, int j, vector<vector<int>>& dp){
        if(i==-1) return j+1;
        if(j==-1) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j] = sol(word1,word2,i-1,j-1,dp);
        else{
            return dp[i][j] = 1+ min(sol(word1,word2,i-1,j,dp),min(sol(word1,word2,i,j-1,dp),sol(word1,word2,i-1,j-1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return sol(word1, word2, word1.size()-1,word2.size()-1,dp);
        
    }
};