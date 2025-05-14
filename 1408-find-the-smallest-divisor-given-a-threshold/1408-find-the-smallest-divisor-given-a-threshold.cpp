class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high=nums[0];
        for(int i=0;i<nums.size();i++){
            high=max(high,nums[i]);
        }
        int ans=high;
        while(low<=high){
            int mid = (low+high)/2;
            int val=0;
            for(int i=0;i<nums.size();i++){
                val+=(nums[i]+mid-1)/mid;
                
            }
            if(val>threshold) low=mid+1;
            else{
                ans=mid;
                high = mid-1;
            }

        }
        return low;
        
    }
};