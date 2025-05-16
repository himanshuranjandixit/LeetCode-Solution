class Solution {
public:
    void dp(vector<int>& candidates, vector<vector<int>>& ans, vector<int>&v, int sum, int target,int indx){
        if(indx==candidates.size() || sum>target) return;
        if(sum==target){
            ans.push_back(v);
            return;
        }
        v.push_back(candidates[indx]);
        dp(candidates,ans,v,sum+candidates[indx],target,indx);
        v.pop_back();
        dp(candidates,ans,v,sum,target,indx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        dp(candidates,ans,v,0,target,0);
        return ans;

        
    }
};