class Solution {
public:
    // int solve(vector<int>& nums, int indx,vector<int>& dp){
    //     if(indx>=nums.size()-1) return dp[indx]=0;
    //     if(dp[indx]!=-1) return dp[indx];
    //     int ans=1e9;
    //     for(int i=1;i<=nums[indx];i++){
    //         if(indx+i<nums.size()){
    //             ans= min(ans,1+solve(nums,indx+i,dp));
    //         }
    //     } 
    //     return dp[indx]=ans;
    // }
    int jump(vector<int>& nums) {
        // vector<int>dp(nums.size(),-1);
        // int count=0;
        // solve(nums,0,dp);
        // return dp[0];
        int l=0;
        int r=0;int ans=0;
        while(r<nums.size()-1){
            int maxi=0;
            for(int i=l;i<=r;i++){
                maxi=max(i+nums[i],maxi);
            }
            l=r+1;
            r=maxi;
            ans++;
        }
        return ans;

        
    }
};