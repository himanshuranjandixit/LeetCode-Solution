class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[i-nums[i]]++;
        }
        long long count=0;
        for(auto it : mpp){
            count+=(it.second-1)*1LL*it.second/2;
        }
        int n=nums.size();
        long long ans=n*1LL*(n-1)/2;
        ans-=count;
        return ans;
        
    }
};