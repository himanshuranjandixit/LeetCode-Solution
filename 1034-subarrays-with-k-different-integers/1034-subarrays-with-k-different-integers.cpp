class Solution {
public:
    int solve(vector<int>nums,int k){
        unordered_map<int,int>mpp;
        int low=0;
        int high=0;
        int count=0;
        while(high<nums.size()){
            mpp[nums[high]]++;
            while(mpp.size()>k){
                mpp[nums[low]]--;
                if(mpp[nums[low]]==0) mpp.erase(nums[low]);
                low++;
            }
            count+=high-low+1;
            high++;
        }
        return count;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // while(high<nums.size()){
        //     if(mpp.find(nums[high])==mpp.end()){
        //         mpp[nums[high]]++;
        //         if(mpp.size()==k) count+=high-low+1;
        //         if(mpp.size()>k){
        //             while(mpp.size()>k){
        //                 mpp[nums[low]]--;
        //                 if(mpp[nums[low]]==0) mpp.erase(nums[low]);
        //                 low++;
        //             }
        //             count+=high-low+1;
        //         }
        //     }
        //     else{
        //         while(mpp.find(nums[high])!=mpp.end()){
        //             mpp[nums[low]]--;
        //             if(mpp[nums[low]]==0) mpp.erase(nums[low]);
        //             low++;
        //         }
        //         mpp[nums[high]]++;
        //         if(mpp.size()==k) count+=high-low+1;
        //     }
        //     high++;
        // }
        // return count;
        if(k==0) return solve(nums,k);
        return solve(nums,k)-solve(nums,k-1);
        
    }
};