class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=nums[0];
        int sum=nums[0];
        if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                sum+=nums[i];
            }
            else{
                ans=max(sum,ans);
                sum=nums[i];
            }

        }
        ans=max(sum,ans);
        return ans;
        
    }
};