class Solution {
public:
   int m = 1e9 +7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int>v(n+1);
        for(auto it:requests){
            v[it[0]] +=1;
            v[it[1]+1]-=1;
        }
        // for(int i=0;i<n+1;i++) cout<<v[i]<<" ";
        // cout<<endl;
        // cout<<v[0]<<" ";
        vector<pair<int,int>>vp;
        vp.push_back({v[0],0});
        for(int i=1;i<n+1;i++){
            v[i]+=v[i-1];
            vp.push_back({v[i],i});
            // cout<<v[i]<<" ";
        }
        // cout<<endl;
        sort(vp.begin(),vp.end());
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=n;i>0;i--){
            // cout<<vp[i].first<<" "<<vp[i].second<<endl;
            int idx = vp[i].second;
            int fact = vp[i].first;
            ans = (ans%m + (nums[i-1]*1LL*fact)%m)%m;
        }
        return (int)ans;


        
    }
};