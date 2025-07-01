class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        vector<long long>dp(31,0);
        dp[0]=1;
        for(int i=1;i<31;i++){
            dp[i]=2*dp[i-1]+1;

        }
        int ans=0;
        int sign =1;
        for(int i=30;i>=0;i--){
            int ith_bit = ((1<<i)&n);
            if(ith_bit){
                ans = ans + sign*dp[i];
                sign*=-1;
            }
        }
        return ans;
        
    }
};