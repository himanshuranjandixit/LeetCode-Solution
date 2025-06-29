class Solution {
public:
    int M = 1e9 +7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>power(nums.size()+1);
        power[0]=1;
        for(int i=1;i<nums.size()+1;i++){
            power[i] = (power[i-1]*2)%M;
        }
        int i=0;int j=nums.size()-1;
        int ans=0;
        while(i<=j){
            int min = nums[i];
            int max = nums[j];
            if(min+max>target) j--;
            else{
                ans  = (ans + power[j-i])%M;
                i++;

            }
        }
        return ans;

        
    }
};