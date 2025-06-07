class Solution {
public:
    bool solve(vector<int>&nums, __int128 product,__int128 target,int indx){
        if(product>target) return false;
        if(product==target) return true;
        if(indx==nums.size()) return false;
        if(solve(nums,product*nums[indx],target,indx+1)) return true;
        if(solve(nums,product,target,indx+1)) return true;
        return false;


    }
    bool checkEqualPartitions(vector<int>& nums, __int128 target) {
        __int128 product=1;
        for(int i=0;i<nums.size();i++){
            product*=(__int128)nums[i];
            if(product>target*target) return false;
        }
        if(product!=target*target) return false;
        return solve(nums,1,target,0);
        
        
    }
};