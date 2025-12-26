class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums[0]-=k;
        for(int i=1;i<nums.size();i++){
            nums[i]=min(max(nums[i]-k,nums[i-1]+1),nums[i]+k);
        }
        set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        return st.size();
        
    }
};