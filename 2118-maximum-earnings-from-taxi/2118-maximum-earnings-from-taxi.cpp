class Solution {
public:
    vector<int>start;
    vector<long long>dp;
    long long solve(vector<vector<int>>& rides, int indx){
        if(indx>=rides.size()) return 0;
        if(dp[indx]!=-1) return dp[indx];
        long long taken =0;
        int next_indx = lower_bound(start.begin(),start.end(),rides[indx][1]) - start.begin();
        taken = rides[indx][1] - rides[indx][0] + rides[indx][2] + solve(rides,next_indx);
        long long not_taken = solve(rides,indx+1);
        return dp[indx] = max(taken,not_taken);


    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        for(auto it :rides) start.push_back(it[0]);
        dp.resize(rides.size(),-1);
        return solve(rides,0);
        
    }
};