class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<nums.size()-1;j++){
                auto it = lower_bound(nums.begin(),nums.end(),nums[i]+nums[j]);
                int k= it- nums.begin();
                ans+=k-j-1;
            }
        }
        return ans;

        
    }
};