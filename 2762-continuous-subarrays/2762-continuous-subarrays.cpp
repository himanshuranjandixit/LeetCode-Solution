class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int left=0;
        int right=0;
        map<int,int>mpp;
        int n = nums.size();
        while(right<n){
            mpp[nums[right]]++;
            while(mpp.rbegin()->first - mpp.begin()->first >2){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) mpp.erase(nums[left]);
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
            

        
    }
};                  