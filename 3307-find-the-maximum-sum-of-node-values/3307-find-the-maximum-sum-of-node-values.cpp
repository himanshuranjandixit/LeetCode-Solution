class Solution {
    long long ans=0;
public: 
    void solve(vector<int>& nums, int k , vector<vector<int>>& edges, long long sum,int indx, vector<long long>& dp){
        if(indx>=edges.size()){
            ans=max(ans,sum);
            dp[indx]=ans;
            return;
        }
        if(dp[indx]!=-1){
            ans=max(ans,dp[indx]); 
            return;
        }
        int org1=nums[edges[indx][0]];
        int org2 = nums[edges[indx][1]];
        if((nums[edges[indx][0]]+nums[edges[indx][1]])<((nums[edges[indx][0]]^k) +(nums[edges[indx][1]]^k ))){
            int s =((nums[edges[indx][0]]^k) + (nums[edges[indx][1]]^k))- (nums[edges[indx][0]]+nums[edges[indx][1]]);
            nums[edges[indx][0]]=nums[edges[indx][0]]^k;
            nums[edges[indx][1]]=nums[edges[indx][1]]^k;
            solve(nums,k,edges,sum+s,indx+1,dp);
            nums[edges[indx][0]]=org1;
            nums[edges[indx][1]]=org2;
        }
        solve(nums,k,edges,sum,indx+1,dp);
        dp[indx]=ans;
        return;

    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // long long sum=0;
        // vector<vector<int>>dup;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(i==j) continue;
        //         vector<int>v;
        //         v.push_back(i);
        //         v.push_back(j);
        //         dup.push_back(v);
        //     }
        // }
        // for(auto it : nums) sum+=it;
        // vector<long long >dp(nums.size()+1,-1);
        // solve(nums,k,dup,sum,0,dp);
        // return ans;

        long long sum=0;
        long long mini=INT_MAX;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=(long long)max(nums[i],(nums[i]^k));
            mini=min(mini,(long long)abs(nums[i]-(nums[i]^k)));
            if((nums[i]^k)>nums[i]) count++;
        }
        if(count%2==0) return sum;
        return sum-mini;



        
    }
};