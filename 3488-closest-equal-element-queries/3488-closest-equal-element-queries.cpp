class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mpp;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(auto it : queries){
            int num = nums[it];
            int ress =INT_MAX;
            int idx = lower_bound(mpp[num].begin(),mpp[num].end(),it)-mpp[num].begin();
            int res = INT_MAX;
            int right = mpp[num][(idx + 1) % mpp[num].size()];
            int left = mpp[num][(idx - 1 + mpp[num].size()) % mpp[num].size()];
            int d1 = abs(right - it);
            int d2 = abs(left - it);
            res = min(res, min(d1, n - d1));
            res = min(res, min(d2, n - d2));
            if(res==0) ans.push_back(-1);
            else ans.push_back(res);
        }
        return ans;
        
    }
};