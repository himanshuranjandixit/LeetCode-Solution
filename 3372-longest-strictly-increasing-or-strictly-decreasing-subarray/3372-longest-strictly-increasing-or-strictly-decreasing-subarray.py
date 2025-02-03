class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        asc=1
        dsc=1
        ans=1
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1] :
                dsc=1
                asc=asc+1
            elif nums[i]<nums[i-1]:
                asc=1
                dsc+=1
            else :
                asc=1
                dsc=1
            ans=max(ans,max(asc,dsc))
        return ans
                
        