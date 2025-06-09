class Solution {
public:
    int solve(vector<int>& arr, int k, int indx,vector<int>& dp){
        if(indx==arr.size()) return 0;
        if(dp[indx]!=-1) return dp[indx];
        int len=0;
        int maxi=-1;
        int ans=-1;
        for(int i=indx;i<min(indx+k,int(arr.size()));i++){
            len++;
            maxi =max(maxi,arr[i]);
            int sum = maxi*len + solve(arr,k,i+1,dp);
            ans=max(ans,sum);

        }
        return dp[indx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1,-1);
       return solve(arr,k,0,dp);
        
    }
};