class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        mpp1={}
        mpp2={}
        ans=[]
        for it in queries:
            if it[0] in mpp1:
                mpp2[mpp1[it[0]]]-=1
                if mpp2[mpp1[it[0]]]==0:
                    mpp2.pop(mpp1[it[0]])
            mpp1[it[0]]=it[1]
            if mpp1[it[0]] in mpp2 :
                mpp2[mpp1[it[0]]]+=1
            else:
                mpp2[mpp1[it[0]]]=1
            ans.append(len(mpp2))
        
        return ans

                
        