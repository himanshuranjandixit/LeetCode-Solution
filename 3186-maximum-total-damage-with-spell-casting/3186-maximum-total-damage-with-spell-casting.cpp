class Solution {
public:
    vector<long long> dp;
    vector<pair<int,long long>> v;
    long long solve(int i){
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];
        long long not_take = solve(i - 1);
        long long take = v[i].second;
        int j = i-1;
        while (j >= 0 && v[i].first <= v[j].first+2) {
            j--;
        }
        take += solve(j);
        return dp[i] = max(take,not_take);
    }

    long long maximumTotalDamage(vector<int>& power) {
        map<int,long long> mp;
        for (int it : power){
            mp[it] += it;
        }
        for(auto it : mp){
            v.push_back(it);
        }
        dp.assign(v.size(), -1);
        return solve((int)v.size()-1);
    }
};
