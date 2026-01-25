class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        
        ans=nums[k-1]-nums[0];
        for(int i=k;i<nums.size();i++){
            ans=min(nums[i]-nums[i-k+1],ans);
        }
        return ans;
        
    }
};