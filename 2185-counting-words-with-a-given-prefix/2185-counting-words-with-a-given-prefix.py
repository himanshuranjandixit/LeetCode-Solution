class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        count=0
        for word in words:
            Isprefix=1
            if (len(pref)>len(word)):
                continue
            for i in range(0,len(pref)):
                if (word[i] != pref[i]):
                    Isprefix=0
                    break
            count+=Isprefix
        return count

        