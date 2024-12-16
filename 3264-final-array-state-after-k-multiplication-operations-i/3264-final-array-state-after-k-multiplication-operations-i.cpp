class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k>0){
            int min=INT_MAX;
            int ind=-1;
            for(int i=0;i<nums.size();i++){
                if(min>nums[i]){
                    ind=i;
                    min=nums[i];
                }
            }
            nums[ind]*=multiplier;
            k--;
        }
        return nums;
    }
};