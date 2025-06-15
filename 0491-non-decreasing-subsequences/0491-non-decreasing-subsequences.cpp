class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int>& nums, int indx, vector<int>& v){
        if(indx==nums.size()){
            if(v.size()>1) ans.insert(v);
            return;
        }
        if(v.size()==0){
            v.push_back(nums[indx]);
            solve(nums,indx+1,v);
            v.pop_back();
        }
        else if(v[v.size()-1]<=nums[indx]){
            v.push_back(nums[indx]);
            solve(nums,indx+1,v);
            v.pop_back();
        }
        solve(nums,indx+1,v);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>v;
        solve(nums,0,v);
        vector<vector<int>>sub;
        for(auto it :ans){
            sub.push_back(it);
        }
        return sub;
        
        
    }
};