class Solution {
public:
    double ans=1;
    int check=0;
    double myPow(double x, long long n) {
        // if(n<0){
        //     long long n=-n;
        //     check=1;
        
        // }
        // if(n==0){
        //     return 1;
        // }
        // ans=x*myPow(x,n-1);
        // if(check==1) return 1/ans;
        // return ans;
        long long nn;
        if(n<0) nn=-1*n;
        else nn=n;
        double ans=1.0;
        while(nn>0){
            if(nn%2==0){
                x*=x;
                nn=nn/2;
            }
            else{
                ans*=x;
                nn--;
            }
        }
        if(n<0){
            ans=(1.0/ans);
            return ans;
        }
        return ans;

        
    }
};