class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans = 0 ;
        while(true){
            long long val = (long long)num1 - 1LL*ans*num2;
            if(val<0) break;
            if(__builtin_popcountll(val) <= ans && ans <= val) return ans;
            ans++;
        }
        return -1;
    }
};