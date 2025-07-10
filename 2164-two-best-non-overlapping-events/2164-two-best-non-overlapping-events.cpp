class Solution {
public:
    vector<vector<int>>dp;
    vector<int> start;
    long long solve(vector<vector<int>>& events, int k, int indx) {
        if(indx >= events.size() || k == 0) return 0;

        if (dp[indx][k]!=-1) return dp[indx][k];
        int next_indx = upper_bound(start.begin(), start.end(), events[indx][1]) - start.begin();
        long long taken =0;
        taken = events[indx][2] + solve(events, k - 1, next_indx);
        long long not_taken = solve(events, k, indx + 1);

        return dp[indx][k] = max(taken, not_taken);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        for (auto& it : events) start.push_back(it[0]);
        dp.resize(events.size(),vector<int>(3,-1));
        return (int)solve(events, 2, 0);
    }
};
