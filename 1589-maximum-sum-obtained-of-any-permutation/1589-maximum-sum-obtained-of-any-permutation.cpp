class Solution {
public:
    int M = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int>diff(n);
        for(auto it : requests){
            diff[it[0]] +=1;
            if(it[1]+1 != n) diff[it[1]+1] -=1;
        }
        for(int i=1;i<n;i++){
            diff[i] += diff[i-1];
        }
        sort(diff.begin(),diff.end());
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans + 1LL*diff[i]*nums[i])%M;
        }
        return ans;
        
    }
};