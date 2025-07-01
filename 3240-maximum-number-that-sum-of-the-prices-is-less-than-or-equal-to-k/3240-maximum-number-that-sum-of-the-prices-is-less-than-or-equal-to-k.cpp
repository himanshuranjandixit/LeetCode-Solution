class Solution {
public:
    long long solve(long long num, int x){
        long long ans = 0;
        for(long long i=x-1;i<64;i+=x){
            if((1LL<<i)&num) ans++;


        }
        return ans;
    }
    long long countSetBitsUptoN(long long n, long long x) {
        vector<long long> bitsum(65, 0);
        long long ans = 0;
        while (n > 0) {
            long long msb = log2(n);
            long long val = (1LL << msb);
            bitsum[msb] += (n - val + 1);
            for (int i = 0; i < msb; i++)
                bitsum[i] += val / 2;
            n -= val;
        }
        for (int i = 0; i < 65; i++) {
            if ((i + 1) % x == 0)
                ans += bitsum[i];
        }
        return ans;
    }
    long long findMaximumNumber(long long k, int x) {
        long long low = 0 ;
        long long high = 1e15;
        long long ans=0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long result = countSetBitsUptoN(mid,x);
            if(result<=k){
                ans = mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;

        
    }
};