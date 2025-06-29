class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int indx, vector<int>& v,vector<int>& vis){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        if(indx==nums.size()) return ;
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                v.push_back(nums[i]);
                vis[i]=1;
                solve(nums,indx+1,v,vis);
                v.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
        vector<int>vis(nums.size(),0);
        solve(nums,0,v,vis);
        return ans;
        
    }
};