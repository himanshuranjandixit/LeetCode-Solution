class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int asc=1;
        int dsc=1;
        int ans=1;
        for(int i=0 ; i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                asc++;
                dsc=1;
            }
            else if(nums[i+1]<nums[i]){
                dsc++;
                asc=1;
            }
            else{
                dsc=1;
                asc=1;
            }
            ans=max(ans,max(asc,dsc));
        }
        return ans;
        
    }
};