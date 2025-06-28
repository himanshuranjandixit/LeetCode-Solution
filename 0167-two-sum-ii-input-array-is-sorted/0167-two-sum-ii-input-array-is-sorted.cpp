class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                for(auto it:mpp[target-nums[i]]){
                    if(it!=i){
                        return {i+1,it+1};
                    }
                }
            }
        }
        return {};
    }
};