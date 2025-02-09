class Solution:
    def maxDifference(self, s: str) -> int:
        char_int_mpp=defaultdict(int)
        maxi=float('-inf')
        for it in s:
            char_int_mpp[it]+=1
        for it2 in char_int_mpp:
            if char_int_mpp[it2]%2!=0:
                odd=char_int_mpp[it2]
                for it1 in char_int_mpp:
                    if char_int_mpp[it1]%2==0:
                        even=char_int_mpp[it1]
                        maxi=max(maxi,odd-even)
        
        return maxi

        