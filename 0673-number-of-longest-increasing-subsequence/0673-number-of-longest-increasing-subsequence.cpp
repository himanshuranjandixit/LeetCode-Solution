class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        vector<int>count(nums.size(),1);
        int maxlen=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                    count[i]+=count[j];
                }
            }
            maxlen=max(maxlen,dp[i]);
        }
        int res =0;
        for(int i=0;i<nums.size();i++){
            if(maxlen==dp[i]){
                res+=count[i];
            }
        }
        return res;
        
    }
};