class Solution {
public:
    int dp[101][101][2];
    int solve(vector<int>& piles, int turn , int indx, int m){
        if(indx>=piles.size()){
            return 0;
        }
        if(dp[indx][m][turn%2]!=-1) return dp[indx][m][turn%2];
        int res = (turn%2==0) ? -1 : INT_MAX;
        int sum=0;
        for(int i=indx; i<indx+2*m ; i++){
            if(i==piles.size()) break;
            sum+=piles[i];
            int M = max(m,i-indx +1);
            if(turn%2==0) res = max(res, sum+ solve(piles,turn+1,i+1,M));
            else res= min(res, solve(piles,turn+1,i+1,M) );
        }
        return dp[indx][m][turn%2] = res ;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,0,1);
        
    }
};