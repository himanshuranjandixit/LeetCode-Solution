class Solution:
    def reverseWords(self, s: str) -> str:
        words=s.split()
        ans=""
        for i in range(len(words)-1,-1,-1):
            ans+=words[i]
            if i !=0:
                ans+=" "
        return ans 
            




        