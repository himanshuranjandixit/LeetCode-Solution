class Solution {
public:
    int minDistance(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        int ans=0;
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0+ max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        ans=dp[s1.size()][s2.size()];
        return s1.size()+s2.size()-2*ans;
        
    }
};