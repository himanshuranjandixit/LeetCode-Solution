class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int numofzero =0;
        int zeroindx=-1;
        int ans=0;
        while(r<nums.size()){
            if(nums[r]==0 && numofzero==1){
                l=zeroindx+1;
                zeroindx=r;
            }
            if(nums[r]==0 && numofzero==0){
                zeroindx=r;
                numofzero=1;
            }
            ans=max(ans,r-l);
            r++;
        }
        // if(zeroindx==-1) return ans-1;
        return ans;

        
    }
};