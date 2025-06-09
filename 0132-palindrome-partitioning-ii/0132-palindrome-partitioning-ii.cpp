class Solution {
public:
    bool check(string& ss, int i,int j){
        while(i<j){
            if(ss[i]!=ss[j]) return false;
            i++;j--;
        }
        return true;

    }
    int solve(string & s, int i, int j,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        if(check(s,i,j)) return dp[i][j] = 0;
        for(int k=i;k<=j;k++){
            if(check(s,i,k)){
                int cut = 1 + solve(s,k+1,j,dp);
                mini=min(cut,mini);
            }
            
        }
        return dp[i][j] = mini;
    }
    int minCut(string s) {
        s.push_back('$');
        s.insert(s.begin(),'$');
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,1,s.size()-2,dp);
        
    }
};