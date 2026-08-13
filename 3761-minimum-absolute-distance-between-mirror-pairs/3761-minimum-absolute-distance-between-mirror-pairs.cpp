class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while (n != 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }

        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,int>mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mpp.count(nums[i])){
                ans=min(ans,abs(i-mpp[nums[i]]));
            }
            int reverseNum = reverse(nums[i]);
            mpp[reverseNum] = i;
        }
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};