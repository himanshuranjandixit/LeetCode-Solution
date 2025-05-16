class Solution {
public:
    void dp(vector<int>& nums, vector<int>v,int indx, vector<vector<int>>& ans){
        if(indx==nums.size()){
            ans.push_back(v);
            return;
        }
        vector<int>vv(v);
        vv.push_back(nums[indx]);
        dp(nums,vv,indx+1,ans);
        dp(nums,v,indx+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        dp(nums,v,0,ans);
        return ans;
        
    }
}; 