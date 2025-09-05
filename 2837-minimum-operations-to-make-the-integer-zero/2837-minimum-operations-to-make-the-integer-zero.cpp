class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int ans = 0 ;
        for(int k=1;k<=60;k++){
            long long val = (long long)num1 - 1LL*k*num2;
            if(val<0) break;
            if(__builtin_popcountll(val) <= k && k <= val) return k;
        }
        return -1;
    }
};