class Solution {
public:
    bool sol(int indx,int sum, vector<int>& arr,int val,vector<vector<int>>& dp){
        if(sum==val/2) return true;
        if(sum>val/2 || indx==arr.size()) return false;
        if(dp[indx][sum]!=-1) return dp[indx][sum];
        
        bool taken= sol(indx+1,sum+arr[indx],arr,val,dp);
        bool not_taken=sol(indx+1,sum,arr,val,dp);
        
        return dp[indx][sum]= taken||not_taken ;
    }
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int val=accumulate(arr.begin(),arr.end(),0);
        if(val%2!=0) return false;
        vector<vector<int>>dp(arr.size(),vector<int>(val/2,-1));
        return sol(0,0,arr,val,dp);
        
    }
};