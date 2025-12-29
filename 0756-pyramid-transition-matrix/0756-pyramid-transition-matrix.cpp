class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(string curr, unordered_map<string, vector<char>>& mpp, int indx, string next) {
        if(curr.size()==1) return true;
        string key = curr+'|'+to_string(indx)+'|'+next;
        if(dp.count(key)) return dp[key];
        if(indx == curr.size()-1) return dp[key] = solve(next,mpp,0,"");

        string temp = curr.substr(indx,2);
        if(mpp.find(temp)==mpp.end()) return dp[key] = false;
        
        for(auto &it : mpp[temp]) {
            next += it;
            if(solve(curr,mpp,indx+1,next)) return dp[key] = true;
            next.pop_back(); 
        }

        return dp[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mpp;

        for(auto it : allowed) {
            string s = it.substr(0,2);
            mpp[s].push_back(it[2]);
        }
        return solve(bottom,mpp,0,"");
    }
};
