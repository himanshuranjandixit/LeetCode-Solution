class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int M = 1e9+7;
        for(auto it: queries){
            int idx = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            for(int i=idx;i<=r;i+=k){
                nums[i] = (nums[i]*1LL*v)%M;
            }
        }
        int ans=0;
        for(auto it:nums) ans^=it;
        return ans;
    }
};