class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, __int128 target) {
        __int128 product=1;
        for(int i=0;i<nums.size();i++){
            product*=(__int128)nums[i];
            if(nums[i]>target) return false;
        }
        if(target*target==product) return true;
        return false;
        
        
    }
};