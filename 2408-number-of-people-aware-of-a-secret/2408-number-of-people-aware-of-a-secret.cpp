class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);
        dp[1]=1;
        int mod = 1e9+7;
        for(int i=2;i<=n;i++)
        {
            //forget
            if(i-forget>=1 && dp[i-forget]!=0)
            {
               int change = dp[i-forget];
                for(int j = (i-forget);j<i;j++)
                {
                   
                    dp[j]  = (dp[j] - change+mod)%mod;
                    
                }
            }
            dp[i]  = dp[i-1];
          
          
            if(i-delay>=1) dp[i] = (dp[i] + dp[i-delay])%mod;
          
        }
        
    
        return dp[n];
    }
};