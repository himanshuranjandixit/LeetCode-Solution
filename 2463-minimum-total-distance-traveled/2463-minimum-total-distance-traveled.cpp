class Solution {
public:
    vector<vector<long long>>dp;
    long long solve(vector<int>& robot, vector<int>& factorypos, int robotidx, int factoryidx){
        if(robotidx==robot.size()) return 0;
        if(factoryidx==factorypos.size()) return 1e12;
        if(dp[robotidx][factoryidx] != -1) return dp[robotidx][factoryidx];
        long long taken =LLONG_MAX;
        taken = abs(robot[robotidx]-factorypos[factoryidx]) + solve(robot,factorypos,robotidx+1,factoryidx+1);
        long long not_taken = LLONG_MAX;
        not_taken = solve(robot,factorypos,robotidx,factoryidx+1);
        return dp[robotidx][factoryidx] = min(taken,not_taken);

    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>factorypos;
        for(auto it:factory){
            for(int i=0;i<it[1];i++){
                factorypos.push_back(it[0]);
            }
        }
        dp.resize(robot.size()+1,vector<long long>(factorypos.size()+1,-1));
        return solve(robot,factorypos,0,0);
        
        
    }
};