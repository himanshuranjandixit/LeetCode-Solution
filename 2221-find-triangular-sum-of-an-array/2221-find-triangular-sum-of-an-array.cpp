class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n>1){
            vector<int>temp;
            for(int i=0;i<n-1;i++){
                int val = (nums[i]+nums[i+1])%10;
                temp.push_back(val);
            }
            nums =temp;
            n=nums.size();
        }
        return nums[0];

        
    }
};