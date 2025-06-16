class Solution {
public:
    int binarysearch(vector<pair<pair<int,int>,int>>& job, int start){
        int l=0;
        int r =job.size()-1;int ans =job.size();
        while(l<=r){
            int mid= (l+r)/2;
            if(job[mid].first.first>=start){
                ans=mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    int solve(vector<pair<pair<int,int>,int>>& job, int indx,vector<int>& dp){ 
        if(indx==job.size()) return 0;
        if(dp[indx]!=-1) return dp[indx];
        int taken=0;
        int not_taken =0;
        not_taken = solve(job,indx+1,dp);
        int nextindx = binarysearch(job, job[indx].first.second);
        taken = job[indx].second + solve(job,nextindx,dp);
        return dp[indx] = max(taken,not_taken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>>job;
        for(int i=0;i<profit.size();i++){
            job.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        sort(job.begin(),job.end());
        vector<int>dp(job.size()+1,-1);
        return solve(job,0,dp);



        
    }
};