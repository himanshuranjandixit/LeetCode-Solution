class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN;
        int high=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
            maxi=max(maxi,nums[i]);
            high+=nums[i];
        }
        int ans=0;
        while(low<=high){
            int mid = (low+high)/2;
            int sum=0;
            int count=1;
            for(auto num:nums){
                if(sum+num>mid){
                    count++;
                    sum=0;
                }
                sum+=num;
            }
            if(count<=k){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;

        
    }
};