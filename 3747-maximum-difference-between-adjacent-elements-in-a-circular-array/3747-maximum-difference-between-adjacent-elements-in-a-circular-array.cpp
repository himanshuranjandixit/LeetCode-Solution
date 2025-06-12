class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxsum = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            maxsum=max(maxsum,abs(nums[i]-nums[i+1]));
        }
        maxsum=max(maxsum,abs(nums[0] -nums[nums.size()-1]));
        return maxsum;
    }
};