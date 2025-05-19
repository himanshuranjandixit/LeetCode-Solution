class Solution {
public:
    int divide(int dividend, int divisor) {
        // long long ans;
        
        // ans=(long long)dividend/(long long)divisor;
        // if(ans>INT_MAX) return INT_MAX;
        // if(ans<INT_MIN) return INT_MIN;
        // return ans;
        long ans=0;
        long n= dividend;
        long d = divisor;
        int sign=1;
        if((n<0 && d>0) || (n>0 && d<0)) sign=-1;
        n=abs(n);
        d=abs(d);
        if(n==d) return sign;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))) cnt++;
            ans+=(1<<cnt);
            n-= (d<<(cnt));
        }
        ans*=sign;
        if(ans== (1<<31) && sign) return INT_MAX;
        if(ans== (1<<31) && !sign) return INT_MIN;
        return ans;
        
    }
};