class Solution {
public:
    bool check(vector<int>& nums,vector<vector<int>>&queries,int k){
        vector<int>freq(nums.size()+1,0);
        for(int i=0;i<k;i++){
            freq[queries[i][0]]+=queries[i][2];
            freq[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1;i<freq.size();i++){
            freq[i]+=freq[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>freq[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0;
        int high = queries.size();
        int ans=-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(check(nums,queries,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    }
};