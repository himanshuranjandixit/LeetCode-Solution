class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it:mpp){
            if(it.second.size()>2){
                int dist = INT_MAX;
                for(int i =2;i<it.second.size();i++){
                    dist = min(dist,it.second[i]-it.second[i-2]);
                }
                if(dist!=INT_MAX) ans =  min(ans,2*dist);
            }
        }
        return (ans != INT_MAX ? ans : -1);
    }
};