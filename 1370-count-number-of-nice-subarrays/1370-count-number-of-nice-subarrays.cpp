class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int low=0;
        int high =0;
        int ans=0;
        int odd=0;
        while(high<nums.size()){
            if(nums[high]%2!=0) odd++;
            if(odd>k){
                while(odd>k){
                    if(nums[low]%2!=0) odd--;
                    low++;
                }
            }
            ans+=high-low+1;
            high++;
            
        }
        low=0;high=0;odd=0;
        int ans1=0;
        if(k==0) return ans;
        while(high<nums.size()){
            if(nums[high]%2!=0)odd++;
            while(odd>k-1){
                if(nums[low]%2!=0) odd--;
                low++;
            }
            ans1+=high-low+1;
            high++;
        }
        return ans-ans1;
        
    }
};