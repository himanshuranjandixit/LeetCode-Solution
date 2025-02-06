class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        ans=0
        mpp=defaultdict(int)
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                mpp[nums[i]*nums[j]]+=1
        for count in mpp.values():
            if count>=2:
                ways = int(count*(count-1)/2)
                ans+=ways*8
                
        return ans

        

