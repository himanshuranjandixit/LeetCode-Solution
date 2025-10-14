class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int res = 1;
        int cnt = 0;
        for(int i = 1; i< nums.size();++i){
            if(nums[i]>nums[i-1]){
                res++;
            }else{
                if(res>=2*k){
                    return true;
                }else if(res>=k){
                    cnt++;
                    res = 1;
                    if(cnt==2)return true;
                }else{
                    cnt = 0;
                    res = 1;
                }
            }
        }
        if(res>=2*k)return true;
        if(res>=k){
            cnt++;
        }
        return (cnt>=2);
    }
};