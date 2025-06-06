class Solution {
public:
    bool check(vector<int>& ans, int num){
        for(auto it : ans){
            int mini=min(it,num);
            int maxi=max(it,num);
            if(maxi%mini!=0) return false;
        }
        return true;
    }
    vector<int> solve(vector<int>& nums, int indx,int prev,vector<vector<vector<int>>>& dp){
        if(indx==nums.size()){
            return {};
        }
        if(!dp[indx][prev+1].empty()) return dp[indx][prev+1];
        vector<int>not_take;
        not_take = solve(nums,indx+1,prev,dp);
        vector<int> take;
        if(prev==-1 || nums[indx]%nums[prev]==0){   
            take = solve(nums,indx+1,indx,dp);
            take.push_back(nums[indx]);
        }
        if(take.size()>not_take.size()) return dp[indx][prev+1] = take;
        else return dp[indx][prev+1] =not_take;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(nums.size()+1));
        ans=solve(nums,0,-1,dp);
        return ans;
        
    }
};