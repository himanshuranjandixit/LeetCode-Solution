class Solution {
public: 
    long long M =1e9 +7;
    long long  power(long long num, long long  n){
        if(n==0) return 1;
        long long half=(power(num,n/2));
        if(n%2==0) return (half*half)%M;
        return (num*half*half)%M;
    }
    int countGoodNumbers(long long n) {
        if(n==1) return 5;
        long long odd;
        long long even;
        even=(n+1)/2;
        odd=n/2;
        long long ans=0;
        ans=(power(5,even)*power(4,odd))%M;
        return (int)ans;
        
        
    }
};