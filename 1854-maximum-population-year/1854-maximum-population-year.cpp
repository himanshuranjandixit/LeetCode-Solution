class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>v;
        for(auto log : logs){
            v.push_back({log[0],1});
            v.push_back({log[1],-1});
        }
        sort(v.begin(),v.end());
        int maxi=0;
        int year =0;
        int cnt=0;
        for(auto it:v){
            cnt += it.second;
            if(cnt>maxi){
                year = it.first;
                maxi=cnt;
            }
        }
        return year;
        
    }
};