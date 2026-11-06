class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        vector<pair<int,int>>v;
        for(int i=0;i<queries.size();i++){
            v.push_back({i,queries[i]});
        }
        sort(v.begin(),v.end(),[](const auto& a, const auto& b){
            return a.second < b.second;
        });
        vector<int>ans(queries.size());
        int left=0;
        int right =0;
        vector<int>active(n);
        int activeserver=0;
        for(int i=0;i<v.size();i++) {
            int qstime = v[i].second - x;
            int qetime = v[i].second;
            while(right < logs.size() && logs[right][1] <= qetime ){
                active[logs[right][0]-1]++;
                if(active[logs[right][0]-1] ==1) activeserver++;
                right++;
            }
            
            while(left < right && left < logs.size() && logs[left][1] < qstime  ){ 
                active[logs[left][0]-1]--;
                if(active[logs[left][0]-1] == 0) activeserver--;
                
                
                left++;
            }
            ans[v[i].first] = n- activeserver;
        }
        return ans;

    }
};