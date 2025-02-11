class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n=len(part)
        i=0
        while part in s:
            s=s.replace(part,"",1)
        return s
        
        