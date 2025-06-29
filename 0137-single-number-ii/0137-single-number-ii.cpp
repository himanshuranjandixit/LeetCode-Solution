class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int ones=0;int zeros = 0;
            for(auto it:nums){
                if((it>>i)&1) ones++;

            }
            if(ones%3){
                ans = ans | (1<<i);
            }

        }
        return ans;
        
    }
};