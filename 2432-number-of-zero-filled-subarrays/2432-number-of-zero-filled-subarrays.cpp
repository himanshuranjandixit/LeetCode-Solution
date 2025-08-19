class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int l =0;
        int r = 0;
        while(r<nums.size()){
            if(nums[r]!=0){
                while(r<nums.size() && nums[r]!=0) r++;
                l=r;
            }
            while(r<nums.size() && nums[r]==0) r++;
            cout<< l<< " "<<r<<endl;
            ans+=1LL*(r-l+1)*(r-l)/2;
        }
        return ans;
        
    }
};