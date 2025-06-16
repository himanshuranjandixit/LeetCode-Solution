class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<long, int> mpp[n];
        for(int i=0;i<n;i++){
            for(int j=0; j < i; j++){
                long diff = (long)nums[i] - nums[j];
                long count_at_j=0;
                if(mpp[j].count(diff)) count_at_j = mpp[j][diff];
                mpp[i][diff] += count_at_j +1;
                ans += count_at_j;
            }
        }
        return ans;

        
        
    }
};