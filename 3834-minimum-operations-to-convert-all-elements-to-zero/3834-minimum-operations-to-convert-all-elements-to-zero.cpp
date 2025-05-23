class Solution {
public:
    int minOperations(vector<int>& nums) {
        // int count=0;
        // if(nums.size()==1){
        //     if(nums[0]==0) return 0;
        //     return 1;
        // }
        // if(nums.size()==2){
        //     int cnt=0;
        //     if(nums[0]==0) cnt++;
        //     if(nums[1]==0) cnt++;
        //     if(nums[0]==nums[1]) return 1;
        //     return 2-cnt;
            
        // }
        // unordered_map<int,int>mpp;
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==0){
        //         for(auto it:mpp)it.second=false;
        //         continue;
        //     }
        //     if(mpp[nums[i]]==1)continue;
        //     else if(mpp[nums[i]]==0){
        //         count++;
        //         mpp[nums[i]]=1;
        //     }
        //     if(nums[i]>nums[i+1]) mpp[nums[i]]=0;
        // }
        // if(mpp[nums[nums.size()-1]]==0 && nums[nums.size()-1]!=0) count++;
        // return count;

        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int n = nums.size();
        set<int>st{n};
        int ans=0;
        for(int i=0;i<nums.size();i++){
            st.insert(v[i].second);
            if(v[i].first!=0) ans++;
            while(i<nums.size()-1 && v[i].first==v[i+1].first){
                int nextsmallerindx = *st.upper_bound(v[i].second);
                // if(nextsmallerindx==*st.end()) nextsmallerindx=nums.size();
                int nextsameindx = v[i+1].second;
                if(nextsmallerindx<nextsameindx) break;
                i++;
                st.insert(v[i].second);
            }
        }
        return ans;
        
    }
};