class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& stone, int indx, int alice){
        if(indx>=stone.size()) return 0;
        if(dp[indx][alice]!=-1) return dp[indx][alice];
        int res = (alice) ? -1e5 : 1e5;
        int sum =0;
        for(int i=indx; i<indx+3;i++){
            if(i==stone.size()) break ;
            sum += stone[i] ;
            if(alice) res =max(res, sum + solve(stone, i+1, !alice));
            else res = min(res, solve(stone,i+1, !alice));
        }
        return dp[indx][alice] = res ;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size()+1,vector<int>(2,-1));
        int alice =  solve(stoneValue, 0, 1);
        int bob = accumulate(stoneValue.begin(), stoneValue.end(),0) - alice;
        if(alice>bob) return "Alice" ;
        if(bob>alice) return "Bob" ;
        return "Tie";
        
    }
};