class Solution {
public:
    int dp[501][501];
    bool solve(vector<int>& piles, vector<int>& stones,int low, int high, int turn){
        if(low>high) return stones[0] > stones[1];
        if(dp[low][high]!=-1) return dp[low][high];
        stones[turn%2] += piles[low];
        bool low_stones = solve(piles, stones,low+1,high,turn+1);
        stones[turn%2] -= piles[low];
        stones[turn%2] += piles[high];
        bool high_stones = solve(piles,stones, low, high-1, turn +1);
        stones[turn%2] -= piles[high];
        return dp[low][high] = (low_stones | high_stones) ;

    }
    bool stoneGame(vector<int>& piles) {
        int low =0;
        int high = piles.size()-1;
        vector<int>stones(2,0);
        int turn =0;
        memset(dp,-1,sizeof(dp));
        return solve(piles,stones,low,high,turn);
        while(low<high){
            int pile_at_low = piles[low];
            int pile_at_high = piles[high];
            if(pile_at_low>pile_at_high){
                low++;
                stones[turn%2] += pile_at_low;
            }
            else if(pile_at_low <= pile_at_high){
                high--;
                stones[turn%2] += pile_at_high;
            }
            turn++;
        }
        return stones[0] >= stones[1] ;
    }
};