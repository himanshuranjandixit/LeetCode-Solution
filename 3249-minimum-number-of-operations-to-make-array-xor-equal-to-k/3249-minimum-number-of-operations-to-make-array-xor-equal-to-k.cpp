class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xor_value = nums[0];
        for(int i=1;i<nums.size();i++){
            xor_value^=nums[i];
        }
        int ans=0;
        for(int i=31;i>=0;i--){
            if((xor_value&(1<<i)) != (k&(1<<i))){
                ans++;

            }
        }
        return ans;
        
    }
};