class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        S2=sorted(s2)
        S1=sorted(s1)
        if(S1!=S2):
            return False
        count=0
        for i in range(len(s1)):
            if s1[i]!=s2[i]:
                count+=1
        if count==0 or count ==2:
            return True
        return False
        