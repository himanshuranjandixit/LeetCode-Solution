class Solution:
    def findCircleNum(self, isconnected: List[List[int]]) -> int:
        vis=[0]*len(isconnected)
        count=0
        for i in range(len(vis)):
            if vis[i]==0:
                count+=1
                q=[]
                q.append(i)
                while len(q)!=0:
                    val=q.pop()
                    for j in range(len(isconnected)):
                        if isconnected[val][j]==1 and vis[j]==0:
                            vis[j]=1
                            q.append(j)
        return count


        