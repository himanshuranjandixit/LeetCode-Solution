class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),[](const pair<int,int> &a, const pair<int,int>& b){
            return a.first > b.first;
        });
        sort(v.begin(),v.begin()+k,[](const pair<int,int> &a, const pair<int,int> &b){
            return a.second < b.second;
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
        


        
    }
};