class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int ans=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==maxi){
                int len=0;
                while(i<nums.size() && nums[i]==maxi){
                    len++;
                    i++;
                }
                ans=max(ans,len);
            }
            i++;
        }
        return ans;
        
    }
};