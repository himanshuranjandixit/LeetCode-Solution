class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        asc=0
        dsc=0
        ans=0
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1] :
                dsc=0
                asc=asc+1
            elif nums[i]<nums[i-1]:
                asc=0
                dsc+=1
            else :
                asc=0
                dsc=0
            ans=max(ans,max(asc,dsc))
        return ans+1
                
        