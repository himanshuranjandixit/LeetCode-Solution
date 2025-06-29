class Solution {
public:
    set<vector<int>>st;
    void solve(vector<int>& nums, int indx, vector<int>& v,vector<int>& vis){
        if(v.size()==nums.size()){
            st.insert(v);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>v;
        vector<int>vis(nums.size(),0);
        solve(nums,0,v,vis);
        vector<vector<int>> ans;
        for(auto it :st){
            ans.push_back(it);
        }
        return ans;
        
        
    }
};