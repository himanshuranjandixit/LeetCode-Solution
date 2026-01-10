class Solution {
public:
    string s1,s2;
    vector<vector<int>>dp;
    int solve(int i, int j){
        if(i==s1.size() && j== s2.size()) return 0;
        if(i==s1.size()){
            int cost=0;
            for(int k=j;k<s2.size();k++){
                cost+=s2[k];
            }
            return cost;
        }
        if(j==s2.size()){
            int cost = 0 ;
            for(int k =i; k< s1.size();k++){
                cost += s1[k];
            }
            return cost;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = solve(i+1,j+1);
        
        return dp[i][j] = min(s1[i]+ solve(i+1,j) , s2[j]+solve(i,j+1));
        
    }
    int minimumDeleteSum(string S1, string S2) {
        s1=S1;
        s2=S2;
        dp.resize(s1.size()+1,vector<int>(s2.size(),-1));
        return solve(0,0);


        
    }
};