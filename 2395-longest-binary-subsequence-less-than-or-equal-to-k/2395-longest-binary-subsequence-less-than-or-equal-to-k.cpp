class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count=0;
        long long val=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                count++;
            }
            else{
                if(val + 1LL*pow(2,count)<=k){
                    count++;
                    val += pow(2,count-1);
                }
            }
        }
        return count;
        
    }
};