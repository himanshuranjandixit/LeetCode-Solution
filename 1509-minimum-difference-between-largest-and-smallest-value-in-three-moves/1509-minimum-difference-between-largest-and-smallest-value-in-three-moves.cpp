class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<5) return 0;
        // sort(nums.begin(),nums.end()) ;
        // return min(nums[nums.size()-1]-nums[3],(nums[nums.size()-4] - nums[0]));
        int ans = INT_MAX ;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j =n-4 ;
        for(int i = 0 ; i<4 ; i++){
            ans = min(ans,nums[j]-nums[i]);
            j++;
           
        }
        return ans;

    }
};