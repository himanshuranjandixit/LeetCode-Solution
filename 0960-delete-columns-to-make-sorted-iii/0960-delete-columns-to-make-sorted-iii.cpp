class Solution {
public:
    bool solve(int i, int j, vector<string>& strs){
        for(int k=0;k<strs.size();k++){
            if(strs[k][j]>strs[k][i]) return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        vector<int>dp(strs[0].size(),1);
        for(int i=1;i<strs[0].size();i++){
            for(int j=0;j<i;j++){
                if(solve(i,j,strs)){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans= 0;
        for(auto it :dp){
            ans=max(ans,it);
        }
        return strs[0].size()-ans;
    }
};