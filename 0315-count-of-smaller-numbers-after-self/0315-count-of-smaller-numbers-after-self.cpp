class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans(nums.size());
        vector<int>sorted;
        for(int i=nums.size()-1;i>=0;i--){
            int idx = lower_bound(sorted.begin(),sorted.end(),nums[i]) - sorted.begin();
            ans[i]=idx;
            sorted.insert(sorted.begin()+idx,nums[i]);
        }
        return ans;
        
    }
};