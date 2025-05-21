class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0;
        int r=0;
        int count1=0;
        int sum1=0;
        while(r<nums.size()){
            sum1+=nums[r];
            while(sum1>goal){
                sum1-=nums[l];
                l++;
            }
            count1+=r-l+1;
            r++;
        }
        l=0;r=0;
        sum1=0;
        int count2=0;
        if(goal==0) return count1;
        while(r<nums.size()){
            sum1+=nums[r];
            while(sum1>goal-1){
                sum1-=nums[l];
                l++;
            }
            count2+=r-l+1;
            r++;
        }
        return count1-count2;
        
    }
};