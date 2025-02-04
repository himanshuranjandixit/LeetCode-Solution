class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        sum=nums[0]
        ans=nums[0]
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                sum+=nums[i]
            else:
                ans=max(sum,ans)
                sum=nums[i]
        ans=max(ans,sum)
        return ans
        