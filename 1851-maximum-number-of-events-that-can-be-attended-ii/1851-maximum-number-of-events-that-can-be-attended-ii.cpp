class Solution {
public:
    long long values=0;
    vector<int>startTime;
    long long solve(vector<vector<int>>& events, int indx, int k, int endTime,vector<vector<long long>>& dp){
        if(indx==events.size() ||k==0){
            if(k>=0) return 0;
            return INT_MIN;
        } 
        if(dp[indx][k]!=-1) return  dp[indx][k];
        long long taken = 0;
        if(events[indx][0]>endTime){
            int next_indx = upper_bound(startTime.begin(),startTime.end(),events[indx][1]) - startTime.begin();
            taken = events[indx][2] + solve(events,next_indx,k-1, events[indx][1],dp);
        }
        long long not_taken = solve(events,indx+1,k,endTime,dp);
        return dp[indx][k] = max(taken,not_taken);

    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        for(auto it :events){
            startTime.push_back(it[0]);
        }
        vector<vector<long long>>dp(events.size(),vector<long long>(k+1,-1));
        long long ans = solve(events,0,k,-1,dp);
        return (int)ans;

        
    }
};