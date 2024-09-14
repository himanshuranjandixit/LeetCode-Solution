class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);

        }
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                count++;
            }
            else{
                ans=max(ans,count);
                count=0;
            }

        }
        ans=max(ans,count);
        count=0;
        return ans;
        
    }
};