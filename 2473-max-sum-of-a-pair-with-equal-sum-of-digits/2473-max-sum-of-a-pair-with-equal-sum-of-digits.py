class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        mpp=defaultdict(list)
        for num in nums:
            summ = sum(int(digit) for digit in str(num))
            mpp[summ].append(num)
        ans=-1
        for key,value in mpp.items() :
            if len(value)>1:
                value.sort(reverse=True)
                ans=max(ans,value[0]+value[1])
        return ans

        