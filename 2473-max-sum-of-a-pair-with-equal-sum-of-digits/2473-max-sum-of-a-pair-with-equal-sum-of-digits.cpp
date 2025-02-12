class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            int sum=0;
            while(val>0){
                sum+=val%10;
                val/=10;
            }
            mpp[sum].push_back(nums[i]);
        }
        int ans=-1;
        for(auto it : mpp){
            if(it.second.size()>1){
                sort(it.second.begin(),it.second.end(),greater<int>());
                ans=max(ans,it.second[0]+it.second[1]);
            }
        }
        return ans;
        
    }
};