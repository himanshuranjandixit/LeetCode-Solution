class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>>v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[] (auto& a, auto& b){
            return a.second>b.second;
        });
        string ans;
        for(auto it : v){
            ans+=string(it.second,it.first);
        }
        return ans;
    }
}; 