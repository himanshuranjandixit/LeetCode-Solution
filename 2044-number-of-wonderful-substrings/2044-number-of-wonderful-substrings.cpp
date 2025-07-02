class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long >mpp;
        mpp[0]=1;
        long long ans=0;
        long long xorr_val=0;
        for(auto ch:word){
            int shift = ch-'a';
            xorr_val^= (1<<shift);
            ans+=mpp[xorr_val];
            for(char i = 'a' ; i<='j';i++){
                long long value =(xorr_val^(1<<(i-'a')));
                ans+=mpp[value];
            }
            mpp[xorr_val]++;
        }
        return ans;
        
    }
};