class Solution {
public: 
    int dp[1001][1001][2];
    int solve(vector<int>& stones, int i , int j , int sum,int turn){
        if(i>=j){
            return 0;
        }
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        int res = ((turn ==0) ? INT_MIN : INT_MAX);
        int res1=INT_MAX;
        if(turn==0){
            return dp[i][j][turn] = res = max(
                sum-stones[i] + solve(stones, i+1,j,sum -stones[i],!turn),
                sum -stones[j] + solve(stones,i, j-1,sum-stones[j],!turn)
            );
        }
        else{
            return dp[i][j][turn] = res1 = min(
                solve(stones, i+1,j,sum -stones[i],!turn) - sum +stones[i] ,
                solve(stones,i, j-1,sum-stones[j],!turn) - sum  + stones[j] 
            );
        }

    }
    int stoneGameVII(vector<int>& stones) {
        long long sum = accumulate(stones.begin(),stones.end(),0LL);
        memset(dp,-1,sizeof(dp));
        return solve(stones,0,stones.size()-1,sum,0);
        
    }
};