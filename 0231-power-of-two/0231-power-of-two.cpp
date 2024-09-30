class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        // while(n>1){
        //     if(n%2!=0){
        //         return false;
        //     }
        //     n/=2;
        // }
        // return true;
        int ans=n&(n-1);
        if(ans == 0) return true;
        return false;
        
    }
};