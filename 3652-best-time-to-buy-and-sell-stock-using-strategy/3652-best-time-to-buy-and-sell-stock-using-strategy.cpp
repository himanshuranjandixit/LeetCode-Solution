class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long profit =0;
        int n = prices.size();
        long long kprofit_mod =0;
        long long kprofit =0;
        for(int i=0;i<n;i++){
            profit += strategy[i]*prices[i];
        }
        for(int i=0;i<k;i++){
            if(i>=k/2) kprofit_mod+=prices[i];
            kprofit += strategy[i]*prices[i]; 
        }

        // cout<<"original profit  : "<<profit<<endl;
        // cout<<"profit after first modification for first k : "<<kprofit_mod<<endl;


        long long profit_firstk = profit-kprofit+kprofit_mod;
        // cout<<"profit modify first k : "<<profit_firstk<<endl;
        long long ans = max(profit_firstk,profit);
        for(int i=k;i<n;i++){
            profit_firstk = profit_firstk - prices[i]*strategy[i] + prices[i] +prices[i-k]*strategy[i-k]-prices[i-k/2];
            // cout<<"profit after modification window"<<i-k+2<<" is : "<<profit_firstk<<endl;
            ans=max(ans,profit_firstk);
        }
        return ans;

    }
};